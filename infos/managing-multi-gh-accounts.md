# 🛡️ The Definitive Guide to Multi-Account GitHub SSH Management

This comprehensive manual explains how to perfectly isolate your **Personal**, **Work**, and **Secret (Binary Nomad)** GitHub identities on a single machine. You will never mix up accounts, never leak your personal email to a work repo, and never have to type a password again.

---

## 📑 Table of Contents

- [🛡️ The Definitive Guide to Multi-Account GitHub SSH Management](#️-the-definitive-guide-to-multi-account-github-ssh-management)
  - [📑 Table of Contents](#-table-of-contents)
  - [Why This Guide?](#why-this-guide)
  - [Prerequisites](#prerequisites)
  - [Step 1: Generating Unique SSH Keys](#step-1-generating-unique-ssh-keys)
  - [Step 2: Setting Up the SSH Agent](#step-2-setting-up-the-ssh-agent)
    - [For Windows (PowerShell)](#for-windows-powershell)
  - [Step 3: Registering Keys on GitHub](#step-3-registering-keys-on-github)
  - [Step 4: The SSH Config File (The Magic Trick)](#step-4-the-ssh-config-file-the-magic-trick)
    - [Explanation of Settings:](#explanation-of-settings)
  - [Step 5: Verifying Connection \& Known Hosts](#step-5-verifying-connection--known-hosts)
  - [Step 6: Configuring Local Git Identity](#step-6-configuring-local-git-identity)
    - [How it works:](#how-it-works)
    - [Setup for your Secret Project:](#setup-for-your-secret-project)
  - [Step 7: Managing Repositories (Clone \& Push)](#step-7-managing-repositories-clone--push)
    - [A. Cloning a Repository](#a-cloning-a-repository)
    - [B. Pushing Existing Local Code to a New Secret Repo](#b-pushing-existing-local-code-to-a-new-secret-repo)
    - [C. Fixing a Wrong Remote URL](#c-fixing-a-wrong-remote-url)
  - [Troubleshooting Common Issues](#troubleshooting-common-issues)
    - [1. Error: `Permission denied (publickey)`](#1-error-permission-denied-publickey)
    - [2. Error: `Could not resolve hostname bin-nomad`](#2-error-could-not-resolve-hostname-bin-nomad)
    - [3. Wrong author showing up on GitHub commits](#3-wrong-author-showing-up-on-github-commits)
  - [💡 Advanced Tip: The `.ssh` Directory Strategy](#-advanced-tip-the-ssh-directory-strategy)
  - [🎉 Summary](#-summary)

---

## Why This Guide?

If you use one computer for everything, you face a common problem:
*   You push code to your **Personal** GitHub.
*   You try to push to your **Work** GitHub.
*   **Error:** `Permission denied (publickey). fatal: Could not read from remote repository.`

**Why?** Because your computer is trying to use the *same* key for both, and GitHub only accepts that key for the first account. By following this guide, you will create specific "passports" for every account and tell your computer exactly which passport to use for which destination.

---

## Prerequisites

Ensure you have the following installed:
*   **Git:** Download from [git-scm.com](https://git-scm.com).
*   **OpenSSH:** Included natively in Windows 10/11 and macOS/Linux.

---

## Step 1: Generating Unique SSH Keys

Think of an SSH key as a digital passport. You cannot use the same passport for two different citizens. We will use the **Ed25519** algorithm (modern, secure, and fast) and generate one key for each account.

Open **PowerShell** (Windows) or **Terminal** (Mac/Linux):

```powershell
# 1. Ensure the .ssh directory exists
mkdir "$HOME\.ssh" -ErrorAction SilentlyContinue

# 2. Generate Personal Key
# -t ed25519: The algorithm type
# -C: A comment (your email) so you know which key this is
# -f: The file name
ssh-keygen -t ed25519 -C "personal@email.com" -f "$HOME\.ssh\id_ed25519_personal"

# 3. Generate Secret/Binary Nomad Key
ssh-keygen -t ed25519 -C "secret@email.com" -f "$HOME\.ssh\id_ed25519_bin_nomad"
```

> 💡 **Note:** When asked for a passphrase, you can press **Enter** to leave it empty (no password needed to unlock the key). This is convenient for personal machines, but if you want maximum security, type a secure phrase.

**Result:** You will now see files like:
*   `id_ed25519_personal` (The Secret Key) 👈 Never share this.
*   `id_ed25519_personal.pub` (The Public Key) 👈 Upload this to GitHub.

---

## Step 2: Setting Up the SSH Agent

Typing your passphrase (if you set one) 50 times a day is annoying. The **SSH Agent** is a background program that holds your unlocked keys in memory so you don't have to re-authenticate constantly.

### For Windows (PowerShell)

Run these commands to ensure the service is running and add your keys:

```powershell
# Ensure the service is set to Automatic start
Set-Service -Name ssh-agent -StartupType Automatic

# Start the service if it isn't running
Start-Service ssh-agent

# Add your keys to the agent
# This prompts for your passphrase if you set one
ssh-add "$HOME\.ssh\id_ed25519_personal"
ssh-add "$HOME\.ssh\id_ed25519_bin_nomad"

# Verify keys are loaded
ssh-add -l
```

> **Why set `StartupType Automatic`?**
> So you don't have to manually start the agent every time you restart your computer.

---

## Step 3: Registering Keys on GitHub

Now that you have the keys, you must give GitHub the "Public" half so it can verify your identity.

1.  **Copy the Public Key content** (Use `.pub`):
    ```powershell
    # Copy to clipboard (Windows)
    Get-Content "$HOME\.ssh\id_ed25519_bin_nomad.pub" | Set-Clipboard
    ```

2.  **Login to the Target Account** (e.g., your Secret Binary Nomad account).
3.  Navigate to: **Settings** (Top right icon) -> **SSH and GPG keys** (Left sidebar).
4.  Click **New SSH key**.
5.  **Title:** Name it something descriptive, e.g., `Windows-Laptop-HP-Elitebook`.
6.  **Key:** Paste the content from your clipboard (starts with `ssh-ed25519 ...`).
7.  Click **Add SSH key**.

*Repeat this step for your Personal key on your Personal account.*

---

## Step 4: The SSH Config File (The Magic Trick)

This is the most critical section. By default, SSH thinks every request to `github.com` uses your default key. We are going to create **aliases** (fake hostnames) to tell your computer which key to use.

Create or edit the config file at `~/.ssh/config`:

```powershell
notepad "$HOME\.ssh\config"
```

Paste the following. **Order matters!**

```text
# 1. Personal Account (Default)
# If I type git@github.com, use this key.
Host github.com
    HostName github.com
    User git
    IdentityFile ~/.ssh/id_ed25519_personal

# 2. Secret / Binary Nomad Account
# If I type git@bin-nomad, use the Secret Key.
# Note: 'bin-nomad' is a custom alias I invented.
Host bin-nomad
    HostName github.com
    User git
    IdentityFile ~/.ssh/id_ed25519_bin_nomad
```

### Explanation of Settings:
*   **`Host github.com`**: This block applies when you try to connect to `github.com`.
*   **`IdentityFile`**: Tells SSH exactly which private key file to use.
*   **`Host bin-nomad`**: This is the magic. We aren't changing the real host name (GitHub). We are just saying: "Whenever I type 'bin-nomad', actually go to GitHub, but please use the Nomad Key."

---

## Step 5: Verifying Connection & Known Hosts

Before pushing code, verify that SSH is using the correct keys and that GitHub recognizes them.

Run these commands in your terminal:

```powershell
# Test Personal connection
ssh -T git@github.com
# Expected Output: Hi [Personal-Username]! You've successfully authenticated...

# Test Secret connection
ssh -T git@bin-nomad
# Expected Output: Hi [Secret-Username]! You've successfully authenticated...
```

> ⚠️ **First Run Warning:** You might see a warning: `The authenticity of host 'github.com' can't be established.`
> **Type:** `yes`
> This adds GitHub's fingerprint to your `known_hosts` file. This is a security check to ensure you are actually talking to GitHub and not a hacker.

---

## Step 6: Configuring Local Git Identity

**CRITICAL:**
Authenticating (SSH keys) is different from **Attribution** (Who wrote the code?).

If you don't set this up, your commits on your Secret account might show your Personal email, revealing your identity.

### How it works:
1.  **Global Identity:** Your default name/email (set in `.gitconfig`).
2.  **Local Identity:** Overrides the Global setting for **this specific folder only**.

### Setup for your Secret Project:

```powershell
# Navigate to your secret project folder
cd C:\projects\secret-cpp-project

# Check current settings
git config user.name
git config user.email

# Set Local Identity for this repo ONLY
git config user.name "Binary Nomad"
# Use the 'noreply' email to protect your privacy
git config user.email "12345678+username@users.noreply.github.com"
```

*Tip: You can find your `noreply` email in GitHub Settings -> Emails -> Keep my email addresses private.*

---

## Step 7: Managing Repositories (Clone & Push)

Here is where the rubber meets the road. You must use the specific Alias (`github.com` vs `bin-nomad`) in your git commands.

### A. Cloning a Repository

Notice the slight change in the URL.

**For Personal Repos:**
```bash
git clone git@github.com:personal-user/project.git
```

**For Secret/Work Repos:**
```bash
# Notice we use the 'bin-nomad' alias!
git clone git@bin-nomad:binary-nomad-x/secret-project.git
```

### B. Pushing Existing Local Code to a New Secret Repo

You have code locally and created a new repo on your Secret account. How do you push it?

```powershell
cd C:\projects\my-secret-project
git init
git add .
git commit -m "Initial commit"

# IMPORTANT: Set the remote using your Secret Alias
git remote add origin git@bin-nomad:binary-nomad-x/repo-name.git

# Push to main
git branch -M main
git push -u origin main
```

### C. Fixing a Wrong Remote URL

Did you accidentally clone a repo using `github.com` when it should be `bin-nomad`?

```powershell
# Check current URL
git remote -v

# Fix it (just change the host part)
git remote set-url origin git@bin-nomad:username/repo.git
```

---

## Troubleshooting Common Issues

### 1. Error: `Permission denied (publickey)`
*   **Cause:** You are trying to push, but GitHub doesn't recognize the key being used.
*   **Fix:**
    1.  Check your `~/.ssh/config` file. Did you use the right alias (`git@bin-nomad`)?
    2.  Did you run `ssh-add` recently? Restart your terminal and try `ssh-add` again.
    3.  Did you add the **Public** key (`.pub`) to GitHub?

### 2. Error: `Could not resolve hostname bin-nomad`
*   **Cause:** You have a typo in your SSH config file (maybe a trailing space or wrong indentation).
*   **Fix:** Open `~/.ssh/config` and ensure there are no weird characters or extra spaces.

### 3. Wrong author showing up on GitHub commits
*   **Cause:** You forgot to run `git config user.email` locally.
*   **Fix:** Run the commands from **Step 6**. Note: This does NOT fix previous commits (they are history). You will need to amend them or start fresh.

---

## 💡 Advanced Tip: The `.ssh` Directory Strategy

If you work on multiple machines (e.g., Work Laptop, Home PC), you have two choices:

1.  **New Keys:** Generate new keys on every machine (Safest).
2.  **Sync Keys (Advanced):** Copy your `.ssh` folder.
    *   Copy `id_ed25519_personal`, `id_ed25519_bin_nomad`, and the `config` file to the new machine.
    *   **Never** upload the `.ssh` folder to a public cloud repo (Google Drive/DropBox is risky unless encrypted).
    *   Remember to run `Start-Service ssh-agent` on the new machine!

---

## 🎉 Summary
By setting up the **SSH Config** and **Local Git Identity**, you have achieved Developer Nirvana:
*   **Security:** No more passwords.
*   **Privacy:** Your secret work stays secret.
*   **Organization:** Git always knows who you are.