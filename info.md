# C++ Development Guide: Build, Run & Debug

This guide covers workflows for single files, multi-file projects, and CMake-based projects across Windows and Linux environments.

---

## 1. Single File Projects

Best for learning syntax, testing small snippets, or competitive programming.

### Directory Structure

```text
project/
└── main.cpp
```



### Compile & Link

The `-g` flag enables debugging symbols. `-std=c++17` sets the language standard.

**Windows (MinGW/MSYS2):**

```bash
g++ main.cpp -std=c++17 -g -o main.exe
```

**Linux (GCC):**

```bash
g++ main.cpp -std=c++17 -g -o main
```

### Run

**Windows:**

```powershell
.\main.exe
```

**Linux:**

```bash
./main
```

> **Tip:** You can combine compile and run in one command:
>
> - **Linux:** `g++ main.cpp -o main && ./main`
> - **Windows:** `g++ main.cpp -o main.exe; .\main.exe`

---

## 2. Multi-File Projects (Manual Build)

Best for small assignments where you don't want to set up CMake yet.

### Directory Structure

```text
calculator/
├── main.cpp
├── Calculator.cpp
└── Calculator.hpp
```

### Compile & Link

Instead of compiling everything at once, it's better practice to compile objects separately and then link them. This speeds up future builds.

**Step 1: Compile object files (.o)**

```bash
# Windows
g++ -c main.cpp -std=c++17 -g -o main.o
g++ -c Calculator.cpp -std=c++17 -g -o Calculator.o

# Linux
g++ -c main.cpp -std=c++17 -g -o main.o
g++ -c Calculator.cpp -std=c++17 -g -o Calculator.o
```

**Step 2: Link object files into executable**

```bash
# Windows
g++ main.o Calculator.o -o app.exe

# Linux
g++ main.o Calculator.o -o app
```

**Alternative (Quick & Dirty for small projects):**

```bash
g++ *.cpp -std=c++17 -g -o app.exe
```

### Run

**Windows:**

```powershell
.\app.exe
```

**Linux:**

```bash
./app
```

---

## 3. CMake Projects (Recommended)

The industry standard for managing C++ projects. Handles dependencies, compiler flags, and cross-platform builds automatically.

### Directory Structure

```text
my_project/
├── CMakeLists.txt
├── src/
│   ├── main.cpp
│   └── Calculator.cpp
└── include/
    └── Calculator.hpp
```

### Basic `CMakeLists.txt` Example

```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(app src/main.cpp src/Calculator.cpp)
target_include_directories(app PRIVATE include)
```

### Build Workflow

**1. Configure (Generate Build Files)**
Creates a `build` directory and generates Makefiles (Linux) or Ninja/MSBuild files (Windows).

```bash
cmake -S . -B build
```

**2. Build (Compile)**

```bash
cmake --build build
```

**3. Run**
The executable location depends on the generator.

- **Linux:** `./build/app`
- **Windows:** `.\build\Debug\app.exe` (or `.\build\Release\app.exe`)

---

## 4. IDE Workflows

### VS Code

_Recommended Extensions:_ C/C++ Extension Pack, CMake Tools.

#### For Single/Multi-File (tasks.json)

1.  Open the `.cpp` file.
2.  Press `Ctrl + Shift + B` to trigger the default build task.
3.  Run the executable in the integrated terminal.

#### For CMake Projects

1.  Open the folder containing `CMakeLists.txt`.
2.  VS Code will detect CMake automatically.
3.  Select Kit (Compiler): Click the bottom bar selector (e.g., "GCC 15.2.0").
4.  Build: `Ctrl + Shift + P` → `CMake: Build`.
5.  Run/Debug: Use the Play/Debug buttons in the status bar or sidebar.

### CLion (JetBrains)

CLion is CMake-native. It does not use `tasks.json` or `launch.json`.

1.  **Open Project:** Select the folder with `CMakeLists.txt`.
2.  **Toolchain Setup:**
    - Go to `Settings` > `Build, Execution, Deployment` > `Toolchains`.
    - Ensure GCC/G++ (Linux) or MinGW (Windows) is detected.
3.  **Run Configuration:**
    - CLion auto-detects executables defined in `CMakeLists.txt`.
    - Click the **Run ▶** button to build and execute.
    - Click the **Debug 🐞** button to start a debugging session with breakpoints.

---

## 5. Common Compiler Flags Reference

| Flag         | Description                                                       |
| ------------ | ----------------------------------------------------------------- |
| `-std=c++17` | Use C++17 standard. Can be `c++20` or `c++23`.                    |
| `-g`         | Generate debugging information (required for debuggers like GDB). |
| `-O2`        | Optimize code for speed (use for release builds, not debugging).  |
| `-Wall`      | Enable all common warnings. Highly recommended.                   |
| `-Wextra`    | Enable extra warnings.                                            |
| `-o <name>`  | Specify the output filename.                                      |
| `-I <path>`  | Add an include directory for header files.                        |

## 6. Troubleshooting

- **"Cannot find -lstdc++"**: Ensure your compiler toolchain is correctly installed (e.g., `build-essential` on Linux, MSYS2 UCRT64 on Windows).
- **"Undefined reference"**: You likely forgot to link a `.cpp` file or compile it into an object file.
- **VS Code IntelliSense errors**: Check `.vscode/c_cpp_properties.json` and ensure the `compilerPath` points to the correct `g++.exe` or `g++`.


### Key Improvements Made:
1.  **Structure:** Added clear headers and directory tree visuals for better understanding.
2.  **Best Practices:** Introduced separate compilation (`-c`) for multi-file projects, which is how real-world C++ works.
3.  **CMake Details:** Added a sample `CMakeLists.txt` because just running commands isn't enough if the file isn't configured.
4.  **Flags Table:** Added a reference table for common flags so users know what `-g` or `-Wall` actually does.
5.  **IDE Specifics:** Clarified that CLion is CMake-native and doesn't need manual JSON config for building.
6.  **Troubleshooting:** Added a section for common errors.


