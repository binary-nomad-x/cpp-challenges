Multiple computers aur multiple GitHub accounts ko manage karne ke liye **SSH Keys** ka tareeqa sabse best hai. Isse aapko baar-baar username ya password/token nahi dena parta.

Chunkay aap aik **Binary Nomad** hain, toh hum isay thora organized tareeqe se karenge taake aapka "Secret" account aur "Public" account kabhi mix na hon.

---

## Step 1: Har Account ke liye Alag Key Banayein

Apne computer ke terminal (ya Neovim terminal) mein jayein aur har account ke liye alag SSH key generate karein.

**Personal Account ke liye:**

```powershell
ssh-keygen -t ed25519 -C "personal@proton.me" -f "$HOME/.ssh/id_ed25519_personal"

```

**Work/Secret Account ke liye:**

```powershell
ssh-keygen -t ed25519 -C "secret@proton.me" -f "$HOME/.ssh/id_ed25519_secret"

```

*(Jab passphrase mange, toh aap khali chor sakte hain ya koi password rakh sakte hain).*

---

## Step 2: SSH Keys ko GitHub par Add Karein

1. Apni public key copy karein: `cat ~/.ssh/id_ed25519_personal.pub` (Windows par `type` command use karein).
2. GitHub Settings -> **SSH and GPG keys** -> **New SSH Key** par jayein aur paste kar dein.
3. Yehi amal apne doosre account ke liye bhi karein.

---

## Step 3: Magic File - `~/.ssh/config`

Ye sabse important step hai. Hum computer ko batayenge ke kab kaunsi key use karni hai.
`~/.ssh/config` file banayein (ya edit karein) aur ye likhein:

```text
# Personal Account (Default)
Host github.com
    HostName github.com
    User git
    IdentityFile ~/.ssh/id_ed25519_personal

# Secret/Work Account (Alias)
Host github-secret
    HostName github.com
    User git
    IdentityFile ~/.ssh/id_ed25519_secret

```

---

## Step 4: Repository Clone aur Push Kaise Karein?

Ab jab aap koi repository clone karenge, toh host name change kar dena hai.

* **Personal Repo ke liye:** Standard tareeqa.
`git clone git@github.com:username/repo.git`
* **Secret Repo ke liye:** `github.com` ki jagah apna alias `github-secret` likhein.
`git clone git@github-secret:secret-username/repo.git`

---

## Step 5: Local Git Config (The Final Touch)

Har computer par aapka "User Name" aur "Email" alag hona chahiye taake commits par sahi naam aaye. Repository ke folder ke andar ja kar ye command chalayen:

```bash
git config user.name "Binary Nomad"
git config user.email "secret@proton.me"

```

*(Yeh `--global` nahi hona chahiye, taake sirf us specific project ke liye rahe).*

---

### Pro-Tip for Different Computers:

Agar aap USB ya Cloud drive (jaise Proton Drive) use karte hain, toh apni `.ssh` folder ka backup zaroor rakhein (sirf private keys ka, public toh GitHub par hoti hain). Is tarah naye computer par sirf Config file copy karni hogi aur aapka setup ready ho jayega.

**Kya aap chahte hain ke main aapko aik script likh kar doon jo naye computer par ye saara SSH setup automatic kar de?**