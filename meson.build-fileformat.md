### meson.build file contents

Here’s a **very basic `meson.build` file** with comments that explain each part step by step.

```meson
# ============================================================
# meson.build
# This is the main build definition file for a Meson project.
# Meson reads this file to understand how to build your code.
# ============================================================


# ------------------------------------------------------------
# Project declaration
# ------------------------------------------------------------
# This tells Meson:
# - the project name
# - which programming language(s) are used
#
# The version is optional but recommended.
project(
  'hello_meson',        # Project name
  'cpp',                # Language used (c, cpp, etc.)
  version: '1.0'
)


# ------------------------------------------------------------
# Define an executable target
# ------------------------------------------------------------
# executable() tells Meson to build a program.
#
# Arguments:
# 1. Name of the output executable
# 2. Source file(s) used to build it
#
# Meson will automatically choose the right compiler
# and flags for your system.
exe = executable(
  'hello',              # Name of the executable
  'main.cpp'            # Source file
)


# ------------------------------------------------------------
# Optional: install the executable
# ------------------------------------------------------------
# This allows the program to be installed using:
#   meson install
#
# On Linux, it usually goes into /usr/local/bin by default.
install: true
```

### Minimal project layout 🗂️

```
project/
├── meson.build
└── main.cpp
```

### Typical Meson workflow 🔧

```bash
meson setup builddir
CC=clang CXX=clang++ meson setup build-debug --buildtype=debug
CC=clang CXX=clang++ meson setup build-debug --buildtype=release
meson compile -C builddir -v
meson install -C builddir
```

