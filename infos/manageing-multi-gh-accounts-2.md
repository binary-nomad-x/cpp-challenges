# Multi-SSH Key Management on Windows (GitHub)

This guide explains how to generate, configure, and manage multiple SSH keys for different GitHub accounts on a single Windows machine.

## 1. Generate SSH Keys

Open **PowerShell** and generate a unique key for each account. Do not use the default file name; give it a specific name.

```powershell
# Key for Account 1
ssh-keygen -t ed25519 -C "email1@example.com" -f "$HOME\.ssh/id_ed25519_account1"

# Key for Account 2
ssh-keygen -t ed25519 -C "email2@example.com" -f "$HOME\.ssh/id_ed25519_account2"

```

## 2. Add Keys to the SSH Agent

The SSH Agent stores your keys in memory so you don't have to provide them manually.

1. **Start the Service:**
```powershell
Start-Service ssh-agent

```


2. **Add your keys:**
```powershell
ssh-add "$HOME\.ssh/id_ed25519_account1"
ssh-add "$HOME\.ssh/id_ed25519_account2"

```



## 3. Configure the SSH Config File

Create or edit the file at `C:\Users\<YourUser>\.ssh\config`. This file tells SSH which key to use for which "nickname" (Host).

```text
# Account 1 (Primary)
Host github-personal
    HostName github.com
    User git
    IdentityFile C:/Users/Administrator/.ssh/id_ed25519_account1
    IdentitiesOnly yes

# Account 2 (Work/Secondary)
Host github-work
    HostName github.com
    User git
    IdentityFile C:/Users/Administrator/.ssh/id_ed25519_account2
    IdentitiesOnly yes

```

> **Note:** `IdentitiesOnly yes` is crucial. It prevents SSH from trying every key in your agent, which often leads to GitHub identifying you as the wrong user.

## 4. Add Public Keys to GitHub

1. Copy the content of the `.pub` file:
```powershell
cat ~/.ssh/id_ed25519_account2.pub

```


2. Go to **GitHub > Settings > SSH and GPG keys > New SSH Key**.
3. Paste the content and save.

## 5. Usage & Cloning

When working with multiple accounts, you must replace `github.com` in the clone URL with your **Host nickname** defined in the config file.

* **To Clone:**
```bash
git clone git@github-work:username/repo-name.git

```


* **To update an existing repo:**
```bash
git remote set-url origin git@github-work:username/repo-name.git

```



## 6. Debugging Common Issues

### Wrong Username Detected

If `ssh -T git@github-work` shows your old username:

1. **Check Config:** Ensure `IdentitiesOnly yes` is present.
2. **Check Agent:** Run `ssh-add -D` to flush all keys, then re-add only the one you need.
3. **Verbose Test:** Run `ssh -vT git@github-work` to see exactly which key file is being offered to GitHub.

### Permissions Error

Ensure your private key files have restricted permissions. In Windows, right-click the `.ssh` folder > Properties > Security, and ensure only your user has access.

