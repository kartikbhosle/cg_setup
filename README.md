# Computer Graphics Lab Setup

A one-time Windows setup script for running legacy `graphics.h` / WinBGIm Computer Graphics programs with C++ in VS Code.

## What It Installs

- MSYS2
- MINGW64 GCC
- WinBGIm:
  - `graphics.h`
  - `winbgim.h`
  - `libbgi64.a`
- MINGW64 compiler directory in the Windows system PATH
- VS Code extension: **Graphics.h Compiler** by AlbatrossC

The script also verifies GCC, normal C++ compilation, `graphics.h` compilation, and WinBGIm linking.

## VS Code Configuration

This setup intentionally **does not modify**:

- `settings.json`
- `tasks.json`
- `c_cpp_properties.json`
- VS Code terminal profiles

The Graphics.h Compiler extension handles its own Graphics/WinBGI execution workflow and its own additional toolkit/dependencies. Those dependencies are downloaded by the extension when its WinBGI functionality is initialized.

## Student Workflow

After setup:

1. Open VS Code.
2. Open or create a `.cpp` Computer Graphics program.
3. Use the **Graphics.h Compiler** extension to run the Graphics program.

For example:

```cpp
#include <graphics.h>
#include <conio.h>
#include <iostream>
```

The installed MINGW64 environment is also available for normal `g++` usage from a properly configured terminal.

## Requirements

- Windows 10/11
- Administrator access during installation
- Internet connection
- VS Code installed

If the VS Code `code` command is available, the setup installs the extension automatically. Otherwise, install **Graphics.h Compiler** manually from the VS Code Extensions panel.

## Installation

Open **PowerShell as Administrator** and run:

```powershell
Set-ExecutionPolicy -Scope Process Bypass
```

Then navigate to the folder containing the setup script and run:

```powershell
.\CG_Setup_v1.ps1
```

The script performs installation and verification automatically.

## WinBGIm Linking

The WinBGIm environment uses:

```text
libbgi64.a
-lgdi32
-lcomdlg32
-luuid
-loleaut32
-lole32
```

The installer verifies that WinBGIm can be linked successfully.

## Why Two Workflows?

This project intentionally keeps two independent workflows.

### MSYS2 / MINGW64

Provides:

- GCC
- terminal-based `g++`
- general C++ compilation
- WinBGIm development files

### Graphics.h Compiler Extension

Provides:

- convenient Graphics.h execution inside VS Code
- its own WinBGI execution environment
- automatic installation of its additional toolkit when required

The two environments are kept separate so that VS Code JSON configuration does not need to be modified.

## Verification

The installer checks:

```text
MSYS2
  ↓
MINGW64 GCC
  ↓
g++.exe
  ↓
cc1plus.exe
  ↓
Normal C++ compilation
  ↓
graphics.h compilation
  ↓
WinBGIm linking
  ↓
VS Code extension
```

If a required component fails verification, setup stops and reports the failure.

## Important Notes

### Legacy technology

`graphics.h` and WinBGIm are legacy Computer Graphics teaching technologies intended here for college/lab practicals.

### Internet

Internet access is required during installation for MSYS2/GCC packages and may also be required by the VS Code extension when it downloads its own toolkit.

### Administrator privileges

Administrator privileges are required because the setup can install software and modify the system PATH.

### VS Code JSON

Students do **not** need to manually edit:

```text
settings.json
tasks.json
c_cpp_properties.json
```

## Troubleshooting

### `g++` is not recognized

Close and reopen the terminal after installation, then run:

```powershell
g++ --version
```

### `graphics.h` cannot be found

Check:

```text
C:\msys64\mingw64\include\graphics.h
```

and rerun the setup if necessary.

### WinBGIm linking fails

Check:

```text
C:\msys64\mingw64\lib\libbgi64.a
```

The installer normally detects this during its verification stage.

### Extension is not installed

In VS Code, open **Extensions** and search for:

```text
Graphics.h Compiler
```

Install the extension by **AlbatrossC**.

## Recommended Repository Structure

```text
CG_Setup/
│
├── CG_Setup_v1.ps1
├── README.md
└── WinBGIm/
    ├── graphics.h
    ├── winbgim.h
    └── libbgi64.a
```

The current setup script contains the WinBGIm files internally, so the separate `WinBGIm` folder is not required for the script itself.

## Credits

**Created by Kartik Bhosle**

GitHub: https://github.com/kartikbhosle

## Third-Party Software

This setup uses third-party software including:

- MSYS2
- GCC / MINGW64
- WinBGIm
- Visual Studio Code
- Graphics.h Compiler by AlbatrossC

Third-party software and libraries remain subject to their respective licenses and terms.

## License

This setup script is provided for educational and college-lab deployment purposes.

Third-party software, libraries, and extensions remain subject to their respective licenses.
