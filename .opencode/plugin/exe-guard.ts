import type { Plugin } from "@opencode-ai/plugin"
import { spawn } from "node:child_process"
import path from "node:path"

const COMPILER = /(^|[\s;&|(])(g\+\+(?:-\d+)?|clang\+\+(?:-\d+)?|c\+\+)(?=[\s;&|)])/
const NO_LINK = /(^|\s)(-c|-E|-S|-fsyntax-only|-M|-MM|--version|-dumpversion|-print-file-name)(\s|$)/
const BUILD_TOOL = /(^|[\s;&|(])(cmake|make|ninja|ctest|xcodebuild)(?=[\s;&|)])/

function isInsideBuild(root: string, target: string) {
  const buildDir = path.resolve(root, "build")
  return target === buildDir || target.startsWith(buildDir + path.sep)
}

// The command may `cd` first, so a relative path cannot be resolved reliably.
// Absolute paths are unambiguous; relative ones are only trusted when they
// already point at build/.
function targetsBuild(root: string, value: string) {
  if (path.isAbsolute(value)) return isInsideBuild(root, path.resolve(value))
  return value === "build" || value.startsWith("build/")
}

function runCleaner(root: string) {
  const script = path.join(root, "scripts", "clean-exes.sh")
  try {
    const child = spawn("bash", [script], {
      cwd: root,
      detached: true,
      stdio: "ignore",
    })
    child.on("error", () => {})
    child.unref()
  } catch {}
}

export default (async ({ worktree, directory }) => {
  const root = worktree || directory
  let lastClean = 0

  return {
    // Redirect any ad-hoc compile that would drop a binary in a source folder.
    "tool.execute.before": async (input, output) => {
      if (input.tool !== "bash") return
      const args = output.args
      if (!args || typeof args.command !== "string") return

      const cmd = args.command
      if (!COMPILER.test(cmd)) return
      if (NO_LINK.test(cmd)) return
      if (BUILD_TOOL.test(cmd)) return

      const outDir = path.join(root, "build", "run")

      // Locate the -o target, if any.
      const withSpace = /(^|\s)-o\s+("[^"]+"|'[^']+'|\S+)/.exec(cmd)
      const attached = /(^|\s)-o("[^"]+"|'[^']+'|\S+)/.exec(cmd)
      const match = withSpace ?? attached

      let current: string | undefined
      if (match) {
        current = match[2].replace(/^["']|["']$/g, "")
      }

      // Already inside build/ (e.g. an intentional build dir) -> leave it alone.
      if (current && targetsBuild(root, current)) return

      // Derive a name from the first source file mentioned, else from the target.
      const srcMatch = /([\w./-]+\.(?:cpp|cc|cxx|C))\b/.exec(cmd)
      let stem: string
      if (srcMatch) {
        stem = path.basename(srcMatch[1]).replace(/\.(cpp|cc|cxx|C)$/i, "")
      } else if (current) {
        stem = path.basename(current).replace(/\.(exe|out)$/i, "")
      } else {
        stem = "a.out"
      }
      stem = stem.replace(/[^A-Za-z0-9._-]/g, "-")

      // Absolute, so a `cd` earlier in the chain cannot redirect it.
      const out = path.join(outDir, stem)

      let next: string
      if (match) {
        // Swap the output path, and fix any later reference to the old binary
        // so a chained `&& ./oldname` keeps working.
        const old = match[0]
        next = cmd.replace(old, old.replace(match[2], `"${out}"`))
        if (current) {
          const base = path.basename(current)
          const quotedBase = base.replace(/[.*+?^${}()|[\]\\]/g, "\\$&")
          next = next
            .replace(new RegExp(`\\./${quotedBase}\\b`, "g"), `"${out}"`)
            .replace(new RegExp(`(^|[\\s;&|(])\\.\\/${quotedBase}(?=[\\s;&|)])`, "g"), `$1"${out}"`)
        }
      } else {
        // No -o: g++ would write ./a.out into the current directory.
        next = cmd.replace(COMPILER, `$1$2 -o "${out}"`)
      }

      args.command = next
    },

    event: async ({ event }) => {
      const type = (event as { type?: string })?.type
      if (type !== "session.idle" && type !== "session.deleted") return
      // Debounce: a burst of events must not spawn a cleaner per event.
      const now = Date.now()
      if (now - lastClean < 10_000) return
      lastClean = now
      runCleaner(root)
    },
  }
}) satisfies Plugin
