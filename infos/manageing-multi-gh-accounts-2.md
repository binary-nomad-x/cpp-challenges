# 🛡️ **Complete Guide: Multi-Account GitHub SSH Setup on Windows**

**The Definitive Manual for Managing Personal, Work, and Secret GitHub Accounts on a Single Windows PC**

This guide will teach you how to perfectly isolate your **Personal**, **Work**, and **Secret (Binary Nomad)** GitHub
identities. Never mix up accounts, never leak your personal email to work repos, and never type passwords again.

***

## 📑 **Table of Contents**

- [Why This Guide?](#why-this-guide)
- [Prerequisites](#prerequisites)
- [Step 1: Generate Unique SSH Keys](#step-1-generate-unique-ssh-keys)
- [Step 2: Start & Configure SSH Agent](#step-2-start--configure-ssh-agent)
- [Step 3: Add Public Keys to GitHub](#step-3-add-public-keys-to-github)
- [Step 4: Create SSH Config File (The Magic)](#step-4-create-ssh-config-file-the-magic)
- [Step 5: Test Connections](#step-5-test-connections)
- [Step 6: Configure Git Identities Per Repository](#step-6-configure-git-identities-per-repository)
- [Step 7: Clone, Push, and Manage Repositories](#step-7-clone-push-and-manage-repositories)
- [Troubleshooting](#troubleshooting)
- [Advanced Tips](#advanced-tips)
- [Summary](#summary)

***

## **Why This Guide?**

**The Problem:** You have multiple GitHub accounts (Personal, Work, Secret projects) on one Windows PC.

```
❌ PROBLEM: You push to Personal GitHub → ✅ Works
❌ PROBLEM: You push to Work GitHub → ❌ "Permission denied (publickey)"
```

**Why it fails:** Your PC tries to use the **same SSH key** for all GitHub accounts. GitHub only accepts each key for
one account.

**The Solution:** Create unique "digital passports" (SSH keys) for each account + smart routing via SSH config.

***

## **Prerequisites**

✅ **Required Software:**

```
• Git: https://git-scm.com/download/win
• OpenSSH: Built into Windows 10/11 (PowerShell)
```

✅ **Open PowerShell as Administrator** for initial setup.

***

## **Step 1: Generate Unique SSH Keys**

Each GitHub account needs its own **Ed25519** SSH key pair (private + public).

### **1.1 Create `.ssh` Directory**

```powershell
# Run in PowerShell (Admin)
New-Item -ItemType Directory -Force -Path "$env:USERPROFILE\.ssh"
```

### **1.2 Generate Keys for Each Account**

```powershell
# PERSONAL Account Key
ssh-keygen -t ed25519 -C "personal@gmail.com" -f "$env:USERPROFILE\.ssh\id_ed25519_personal"
# Press Enter → No passphrase (convenient) OR set secure passphrase

# WORK Account Key  
ssh-keygen -t ed25519 -C "work@company.com" -f "$env:USERPROFILE\.ssh\id_ed25519_work"

# SECRET Account Key (Binary Nomad)
ssh-keygen -t ed25519 -C "secret@nomad.com" -f "$env:USERPROFILE\.ssh\id_ed25519_bin_nomad"
```

**✅ Result:** 6 files created:

```
id_ed25519_personal          👈 PRIVATE (Never share)
id_ed25519_personal.pub      👈 PUBLIC (Upload to GitHub)

id_ed25519_work              👈 PRIVATE
id_ed25519_work.pub          👈 PUBLIC

id_ed25519_bin_nomad         👈 PRIVATE  
id_ed25519_bin_nomad.pub     👈 PUBLIC
```

***

## **Step 2: Start & Configure SSH Agent**

The SSH Agent holds your unlocked keys in memory (no repeated passphrase entry).

### **2.1 Enable & Start SSH Agent Service**

```powershell
# Set to start automatically on boot
Set-Service -Name ssh-agent -StartupType Automatic

# Start the service
Start-Service ssh-agent

# Verify it's running
Get-Service ssh-agent
```

### **2.2 Add All Keys to Agent**

```powershell
ssh-add "$env:USERPROFILE\.ssh\id_ed25519_personal"
ssh-add "$env:USERPROFILE\.ssh\id_ed25519_work" 
ssh-add "$env:USERPROFILE\.ssh\id_ed25519_bin_nomad"

# Verify keys loaded ✅
ssh-add -l
```

**💡 Pro Tip:** Add these to your PowerShell profile (`$PROFILE`) for auto-loading on terminal start.

***

## **Step 3: Add Public Keys to GitHub**

### **3.1 Copy Public Key to Clipboard**

```powershell
# Copy Personal key
Get-Content "$env:USERPROFILE\.ssh\id_ed25519_personal.pub" | Set-Clipboard

# Copy Work key  
Get-Content "$env:USERPROFILE\.ssh\id_ed25519_work.pub" | Set-Clipboard

# Copy Secret key
Get-Content "$env:USERPROFILE\.ssh\id_ed25519_bin_nomad.pub" | Set-Clipboard
```

### **3.2 Add to GitHub**

1. Login to **target GitHub account**
2. **Settings** → **SSH and GPG keys** → **New SSH key**
3. **Title:** `Windows-Laptop-2026`
4. **Key:** Paste clipboard content
5. **Add SSH key**

**Repeat for each account.**

***

## **Step 4: Create SSH Config File (The Magic)**

This file tells SSH: *"When I say `bin-nomad`, use the secret key!"*

### **4.1 Create Config File**

```powershell
notepad "$env:USERPROFILE\.ssh\config"
```

### **4.2 Paste This Exact Configuration**

```text
# =====================================================
# PERSONAL GitHub (Default - github.com)
# =====================================================
Host github-personal
    HostName github.com
    User git
    IdentityFile %USERPROFILE%\.ssh\id_ed25519_personal
    IdentitiesOnly yes

# =====================================================  
# WORK GitHub
# =====================================================
Host github-work
    HostName github.com
    User git
    IdentityFile %USERPROFILE%\.ssh\id_ed25519_work
    IdentitiesOnly yes

# =====================================================
# SECRET / Binary Nomad GitHub  
# =====================================================
Host github-nomad
    HostName github.com
    User git
    IdentityFile %USERPROFILE%\.ssh\id_ed25519_bin_nomad
    IdentitiesOnly yes
```

### **4.3 Set Correct Permissions**

```powershell
# Windows doesn't need chmod, but verify file exists
Test-Path "$env:USERPROFILE\.ssh\config"
```

**🔑 Key Settings Explained:**

- `Host github-nomad` = Custom nickname/alias
- `HostName github.com` = Real destination
- `IdentityFile` = Which private key to use
- `IdentitiesOnly yes` = **CRITICAL** - Only try this one key!

***

## **Step 5: Test Connections**

**Verify each alias works:**

```powershell
# Test Personal
ssh -T git@github-personal
# ✅ Expected: "Hi personal-username! You've successfully authenticated"

# Test Work  
ssh -T git@github-work
# ✅ Expected: "Hi work-username! You've successfully authenticated"

# Test Secret
ssh -T git@github-nomad  
# ✅ Expected: "Hi binary-nomad! You've successfully authenticated"
```

**First time?** You'll see:

```
The authenticity of host 'github.com (140.82.121.4)' can't be established.
ECDSA key fingerprint is SHA256:...
Are you sure you want to continue connecting (yes/no/[fingerprint])?
```

**Type `yes`** ✅

***

## **Step 6: Configure Git Identities Per Repository**

**SSH handles authentication. Git config handles "who wrote this code?"**

### **6.1 Global Identity (Default)**

```powershell
git config --global user.name "Your Personal Name"
git config --global user.email "personal@gmail.com"
```

### **6.2 Local Identity (Per Project)**

```powershell
# Navigate to project folder
cd C:\projects\secret-nomad-project

# OVERRIDES global settings for THIS folder only
git config user.name "Binary Nomad"
git config user.email "12345678+binary-nomad@users.noreply.github.com"
```

**✅ Verify:**

```powershell
git config user.name    # Should show repo-specific name
git config user.email   # Should show repo-specific email
```

**💡 Find your noreply email:** GitHub Settings → Emails → "Keep my email addresses private"

***

## **Step 7: Clone, Push, and Manage Repositories**

### **7.1 Clone New Repositories**

```
# PERSONAL repo
git clone git@github-personal:yourusername/project.git

# WORK repo  
git clone git@github-work:workusername/project.git

# SECRET repo
git clone git@github-nomad:binary-nomad/secret-project.git
```

### **7.2 Push Existing Local Code**

```powershell
cd C:\my-local-project
git init
git add .
git commit -m "Initial commit"

# Set correct remote (use your alias!)
git remote add origin git@github-nomad:binary-nomad/repo.git
git branch -M main
git push -u origin main
```

### **7.3 Fix Wrong Remote URL**

```powershell
# Check current remote
git remote -v

# Fix it
git remote set-url origin git@github-nomad:username/repo.git

# Verify
git remote -v
```

***

## **Troubleshooting**

| ❌ **Error**                               | ✅ **Solution**                                                                                      |
|-------------------------------------------|-----------------------------------------------------------------------------------------------------|
| `Permission denied (publickey)`           | 1. Wrong alias? Use `git@github-nomad`<br>2. `ssh-add` keys again<br>3. Public key added to GitHub? |
| `Could not resolve hostname github-nomad` | Check `~/.ssh/config` syntax (no extra spaces)                                                      |
| Wrong author on commits                   | Run `git config user.email` **locally** in repo                                                     |
| `ssh-add` forgets keys                    | Add to PowerShell `$PROFILE` for auto-load                                                          |

### **Debug Commands**

```powershell
# See which key is being offered
ssh -vT git@github-nomad

# Clear all keys from agent
ssh-add -D

# List loaded keys
ssh-add -l
```

***

## **Advanced Tips**

### **A. Auto-load Keys on Terminal Start**

Add to PowerShell profile (`notepad $PROFILE`):

```powershell
Start-Service ssh-agent
ssh-add "$env:USERPROFILE\.ssh\id_ed25519_personal"
ssh-add "$env:USERPROFILE\.ssh\id_ed25519_work"
ssh-add "$env:USERPROFILE\.ssh\id_ed25519_bin_nomad"
```

### **B. Multiple Machines**

```
✅ OPTION 1: New keys per machine (Recommended)
✅ OPTION 2: Copy .ssh folder (encrypt before cloud storage)
```

### **C. VS Code Integration**

```
1. Install "GitLens" extension
2. VS Code auto-detects SSH config
3. Clone using Command Palette → "Git: Clone" → paste SSH URL
```

***

## **🎉 Summary Checklist**

| ✅ **Completed** | **Step**                        |
|-----------------|---------------------------------|
| ☐               | Generated 3 unique SSH keys     |
| ☐               | SSH Agent running + keys added  |
| ☐               | Public keys added to GitHub     |
| ☐               | `~/.ssh/config` created         |
| ☐               | `ssh -T git@github-nomad` works |
| ☐               | `git config` set per repo       |

**You are now a Multi-Account GitHub Master! 🚀**

```
Personal: git@github-personal:username/repo
Work:    git@github-work:workuser/repo  
Secret:  git@github-nomad:nomaduser/repo
```

**No more password prompts. No identity leaks. Perfect isolation.** 🎯