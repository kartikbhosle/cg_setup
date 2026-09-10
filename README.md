# 🎨 CG Lab Setup --- `graphics.h` on Windows

> **One-click setup for Computer Graphics lab programs using
> `graphics.h`, WinBGIm, MSYS2 MINGW64, and VS Code.**

This project was created to solve a common college-lab problem: getting
old `graphics.h` / WinBGIm programs to compile and run consistently
across different Windows PCs.

Instead of asking every student to manually install compilers, copy
headers, find libraries, configure linker flags, and fight with VS Code
settings, this project provides an **all-in-one PowerShell installer**.

------------------------------------------------------------------------

## ✨ What does it do?

The installer is designed to configure a Windows PC for Computer
Graphics practicals.

``` text
                CG Lab Setup
                     │
          ┌──────────┴──────────┐
          ▼                     ▼
       MSYS2                 VS Code
          │                     │
      MINGW64                  │
          │                     │
         g++                    │
          │                     │
          └───────┬─────────────┘
                  ▼
              WinBGIm
        ┌─────────┼─────────┐
        ▼         ▼         ▼
   graphics.h  winbgim.h  libbgi64.a
                  │
                  ▼
        CG: Build Current File
                  │
                  ▼
          🎨 Graphics Program
```

The setup targets the **MINGW64 + WinBGIm** combination that was tested
for this project.

------------------------------------------------------------------------

## 🚀 Features

-   Installs/checks **MSYS2**
-   Installs/checks **MINGW64 GCC (`g++`)**
-   Installs the project's known-good WinBGIm files
-   Configures an **MSYS2 MINGW64** terminal profile for VS Code
-   Adds a global VS Code task:
    -   `CG: Build Current File`
-   Works with CG projects located in arbitrary folders
-   Uses the currently open `.cpp` file
-   Uses the required WinBGIm linker libraries automatically
-   Does not require students to manually type long compiler commands
-   Designed to avoid changing the Windows PATH unnecessarily
-   Creates backups before modifying VS Code configuration

------------------------------------------------------------------------

## 🧰 What is included?

The project uses these WinBGIm components:

``` text
graphics.h
winbgim.h
libbgi64.a
```

The headers are from **WinBGIm Version 6.0**. The supplied header
identifies the library as Version 6.0, dated August 9, 2004.

The compiler/linker setup uses:

``` text
MINGW64
```

and the CG build links against:

``` text
libbgi64.a
-lgdi32
-lcomdlg32
-luuid
-loleaut32
-lole32
```

------------------------------------------------------------------------

## 💻 Requirements

### Target machine

-   Windows 10/11
-   Administrator access
-   Internet connection for installing MSYS2 when it is not already
    installed
-   VS Code installed

The installer is intended for **Windows PCs used for the Computer
Graphics lab**.

------------------------------------------------------------------------

## 📦 Installation

### 1. Download the installer

Use the release PowerShell installer from this repository, for example:

``` text
CG_Setup_AllInOne.ps1
```

### 2. Run PowerShell as Administrator

Open:

``` text
Windows PowerShell → Run as administrator
```

Temporarily allow the installer to run:

``` powershell
Set-ExecutionPolicy -Scope Process Bypass
```

### 3. Run the installer

Navigate to the directory containing the installer:

``` powershell
cd "C:\path\to\installer"
```

Then:

``` powershell
.\cg_setup_v4.ps1
```

The installer checks the machine and installs/configures the required
components.

------------------------------------------------------------------------

## 👨‍🎓 Student workflow

After setup, students do **not** need to create a special CG project
directory.

### Step 1 --- Open any CG folder

For example:

``` text
D:\College\CG\Practical1
```

Open that folder in VS Code.

### Step 2 --- Create/open a `.cpp` file

Example:

``` cpp
#include <graphics.h>

int main()
{
    initwindow(800, 600, "Computer Graphics");

    circle(400, 300, 100);

    getch();
    closegraph();

    return 0;
}
```

### Step 3 --- Build

In VS Code:

``` text
Terminal
   → Run Task
      → CG: Build Current File
```

### Step 4 --- Run

From the VS Code MINGW64 terminal:

``` bash
./main.exe
```

A graphics window should open.

------------------------------------------------------------------------

## ⚙️ Build command

The global task essentially performs the equivalent of:

``` bash
g++ <current-file>.cpp \
    -o <current-file>.exe \
    C:\msys64\mingw64\lib\libbgi64.a \
    -lgdi32 \
    -lcomdlg32 \
    -luuid \
    -loleaut32 \
    -lole32
```

This removes the need for students to remember the WinBGIm linker
configuration.

------------------------------------------------------------------------

## 🧪 Verification

The setup should verify that:

``` text
C:\msys64\mingw64\bin\g++.exe
```

exists and that the WinBGIm files are installed under:

``` text
C:\msys64\mingw64\include\
C:\msys64\mingw64\lib\
```

A basic `graphics.h` compilation test should also be performed.

For a real end-to-end test, compile and run a program containing:

``` cpp
#include <graphics.h>
```

and a simple drawing operation such as:

``` cpp
circle(400, 300, 100);
```

------------------------------------------------------------------------

## 🛡️ Safety / existing configurations

The installer is designed with lab PCs in mind, but it should still be
tested against different existing configurations before mass deployment.

Important design goals:

-   Do not unnecessarily modify the Windows PATH.
-   Do not remove an existing standalone MinGW installation.
-   Back up VS Code configuration before modification.
-   Preserve existing VS Code tasks where possible.
-   Add the CG build task rather than replacing unrelated build tasks.

------------------------------------------------------------------------

## 🧩 Why MINGW64?

Modern MSYS2 recommends newer environments such as UCRT64 for new
development. However, this project deliberately uses **MINGW64** because
the WinBGIm static library used by this project was tested with that
environment.

Changing the environment without rebuilding/revalidating the WinBGIm
library can introduce CRT/toolchain compatibility problems.

Therefore:

> **MINGW64 is a deliberate compatibility choice for this legacy
> `graphics.h` lab setup.**

This project is not intended to represent the recommended architecture
for a new modern C++ graphics application.

------------------------------------------------------------------------

## ⚠️ Limitations

`graphics.h` / WinBGIm is legacy technology.

The supplied WinBGIm header itself dates to 2004 and contains a warning
that the library may not be compatible with 64-bit versions of Windows.

This project exists primarily to make a **college Computer Graphics
practical environment** reproducible.

It should not be considered a recommendation for new production graphics
software.

------------------------------------------------------------------------

## 🔧 Troubleshooting

### `g++` is not found

Open the VS Code terminal and check:

``` bash
which g++
```

For this setup, it should resolve to the MINGW64 compiler:

``` text
/mingw64/bin/g++
```

------------------------------------------------------------------------

### `graphics.h: No such file or directory`

Check:

``` text
C:\msys64\mingw64\include\graphics.h
```

The installer should place the header there.

------------------------------------------------------------------------

### `cannot find -lbgi64` / BGI linker errors

Check:

``` text
C:\msys64\mingw64\lib\libbgi64.a
```

Also make sure the build is being performed with the project's MINGW64
configuration.

------------------------------------------------------------------------

### VS Code does not show `CG: Build Current File`

Open:

``` text
Terminal → Run Task
```

and look for:

``` text
CG: Build Current File
```

If it is missing, restart VS Code after installation and check the
user's VS Code task configuration.

------------------------------------------------------------------------

### Existing VS Code configuration causes a setup problem

The installer creates backups before modifying configuration.

Look under:

``` text
%APPDATA%\Code\User\
```

for backup files created by the installer.

Do not delete the backups until the setup has been confirmed to work.

------------------------------------------------------------------------

## 📁 Suggested repository structure

A clean GitHub repository can look like:

``` text
CG-Lab-Setup/
│
├── README.md
├── CG_Setup_AllInOne.ps1
├── LICENSE
└── examples/
    ├── circle.cpp
    ├── line.cpp
    ├── house.cpp
    └── heart.cpp
```

The installer itself contains the required WinBGIm assets, so students
do not need to manually manage the header/library files.

------------------------------------------------------------------------

## 🎓 Why this project exists

This started as a practical problem:

> **"How do we make `graphics.h` work on all the Computer Graphics lab
> PCs?"**

Different machines can have different combinations of:

-   MinGW
-   MSYS2
-   GCC versions
-   VS Code configurations
-   existing build tasks
-   missing WinBGIm files
-   conflicting compiler paths

Manual setup makes every student's machine another debugging problem.

The goal of this project is to turn that into:

``` text
One installer
      ↓
One standardized environment
      ↓
Open VS Code
      ↓
Write CG code
      ↓
Build
      ↓
Run
```

------------------------------------------------------------------------

## 📌 Project status

**Tested successfully on multiple Windows PCs**, including:

-   a PC where the CG environment was already working and VS Code
    configuration was the remaining setup step
-   a second PC where MSYS2 was removed before running the installer

The actual `graphics.h` CG program was successfully compiled and
executed after setup.

Before large-scale lab deployment, test the installer on additional
machines with different existing compiler/VS Code configurations.

------------------------------------------------------------------------

## 🤝 Contributing

Suggestions, bug reports, and improvements are welcome.

If you discover a machine-specific issue, please include:

-   Windows version
-   whether MSYS2 was already installed
-   whether another MinGW installation existed
-   GCC version
-   VS Code version
-   the installer output/error

This makes it easier to reproduce and fix the problem.

------------------------------------------------------------------------

## 📜 License / Third-party notice

This repository's installer/orchestration code can be licensed
separately from the WinBGIm components.

The included WinBGIm header identifies the original library as **WinBGIm
Version 6.0**, authored by Grant Macklem, Gregory Schmelter, Alan
Schmidt, Ivan Stashak, and Michael Main, associated with the University
of Colorado at Boulder.

Before publishing the embedded third-party WinBGIm files publicly,
verify the applicable license/redistribution terms and preserve the
original notices.

------------------------------------------------------------------------

## ❤️ Made for the CG Lab

Built to make the classic:

``` cpp
#include <graphics.h>
```

just work.

**Less setup. Less debugging. More drawing. 🎨**
