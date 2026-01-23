# 🛡️ The Ultimate Guide to Multi-Account GitHub SSH Management

This manual explains how to isolate your **Personal**, **Work**, and **Secret** GitHub accounts on a single machine (or across multiple machines) without ever leaking your identity or needing to type a password.

---

## 📑 Table of Contents

1. [SSH Key Generation](https://www.google.com/search?q=%231-ssh-key-generation)
2. [Setting Up the SSH Agent](https://www.google.com/search?q=%232-setting-up-the-ssh-agent)
3. [Adding Keys to GitHub](https://www.google.com/search?q=%233-adding-keys-to-github)
4. [The SSH Config File (The Secret Sauce)](https://www.google.com/search?q=%234-the-ssh-config-file)
5. [Known Hosts & Initial Connection](https://www.google.com/search?q=%235-known-hosts--initial-connection)
6. [Local Git Identity Configuration](https://www.google.com/search?q=%236-local-git-identity)
7. [Working with Repositories (Push/Clone)](https://www.google.com/search?q=%237-working-with-repositories)

---

## 1. SSH Key Generation

You need a unique identity for each account. We use the **Ed25519** algorithm for maximum security and speed.

Open **PowerShell** and run:

```powershell
# Create folder if it doesn't exist
mkdir "$HOME\.ssh" -ErrorAction SilentlyContinue

# Account 1: Personal
ssh-keygen -t ed25519 -C "personal@email.com" -f "$HOME\.ssh/id_ed25519_personal"

# Account 2: Binary Nomad (Secret)
ssh-keygen -t ed25519 -C "secret@email.com" -f "$HOME\.ssh/id_ed25519_bin_nomad"

```

*When prompted for a passphrase, you can leave it empty or add one for extra security.*

---

## 2. Setting Up the SSH Agent

The SSH Agent holds your keys in memory so you don't have to provide them constantly.

**Run PowerShell as Administrator:**

```powershell
# Set service to start automatically
Set-Service -Name ssh-agent -StartupType Automatic

# Start the service
Start-Service ssh-agent

# Add your keys to the agent
ssh-add "$HOME\.ssh/id_ed25519_personal"
ssh-add "$HOME\.ssh/id_ed25519_bin_nomad"

```

---

## 3. Adding Keys to GitHub

You must tell GitHub that these keys belong to you.

1. **Copy the Public Key:**
```powershell
Get-Content "$HOME\.ssh/id_ed25519_bin_nomad.pub"

```


2. Go to **GitHub Settings** -> **SSH and GPG keys** -> **New SSH Key**.
3. Paste the content and give it a title (e.g., "Windows-Laptop-Nomad").

---

## 4. The SSH Config File

This is the most critical step. It tells your computer: *"If I talk to 'bin-nomad', use the Secret Key. If I talk to 'github.com', use the Personal Key."*

Create or edit the file at `~/.ssh/config`:

```powershell
notepad "$HOME\.ssh\config"

```

**Paste this configuration:**

```text
# Default Account (Personal)
Host github.com
    HostName github.com
    User git
    IdentityFile ~/.ssh/id_ed25519_personal

# Secondary Account (Secret)
Host bin-nomad
    HostName github.com
    User git
    IdentityFile ~/.ssh/id_ed25519_bin_nomad

```

---

## 5. Known Hosts & Initial Connection

Before pushing code, you must verify the connection and add GitHub to your `known_hosts`.

Run this for each "Host" defined in your config:

```powershell
ssh -T git@github.com
ssh -T git@bin-nomad

```

*Type **`yes`** when asked about the authenticity of the host.* You should see:

> *Hi [Username]! You've successfully authenticated...*

---

## 6. Local Git Identity

**CRITICAL:** Git uses a global email by default. To prevent your secret account from showing your personal email in the commit history, set a **Local Identity** inside each project folder.

```powershell
cd C:\projects\secret-cpp-project
git config user.name "Binary Nomad"
git config user.email "12345678+username@users.noreply.github.com"

```

*(Using the `noreply` email from GitHub Settings protects your actual email address from being scraped).*

---

## 7. Working with Repositories

### A. Cloning a Repository

* **Personal:** `git clone git@github.com:personal-user/repo.git`
* **Secret:** `git clone git@bin-nomad:secret-user/repo.git` (Notice the host swap).

### B. Pushing Existing Code

If you have code on your PC and want to push it to a new secret repo:

```powershell
git init
git add .
git commit -m "Initial commit"

# Set the remote using your ALIAS
git remote add origin git@bin-nomad:binary-nomad-x/repo-name.git

git branch -M main
git push -u origin main

```

---

## 💡 Pro Tips for Different PCs

* **Syncing:** Never upload your **Private Keys** (files without `.pub`) to the cloud.
* **Portability:** If you move to a new PC, just copy the `.ssh` folder, run the `Start-Service ssh-agent` command (Step 2), and you are back in business.
* **Verification:** Use `git remote -v` to check which alias a project is currently using.

