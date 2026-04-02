# 🧱 Meson + Ninja + Clang Workflow (C / C++)

## 📦 1. Project Setup

```bash
meson setup builddir
```

Specify compilers (Clang for C and C++):

```bash
CC=clang CXX=clang++ meson setup builddir
```

Reconfigure an existing build:

```bash
meson setup builddir --reconfigure
```

---

## 🏗️ 2. Build

```bash
meson compile -C builddir
```

Or directly with Ninja:

```bash
ninja -C builddir
```

---

## 🧪 3. Run Tests

```bash
meson test -C builddir
```

Verbose output:

```bash
meson test -C builddir --verbose
```

---

## 🚀 4. Run Executable

If Meson knows the target:

```bash
meson run -C builddir <target_name>
```

Or manually:

```bash
./builddir/your_executable
```

---

## 🧹 5. Clean Build

```bash
ninja -C builddir clean
```

Or wipe everything:

```bash
rm -rf builddir
```

---

## ⚙️ 6. Build Options

List options:

```bash
meson configure builddir
```

Set options:

```bash
meson configure builddir -Dbuildtype=release
```

Common build types:

* `debug`
* `release`
* `debugoptimized`
* `minsize`

---

## 🧠 7. Compiler Flags (Clang)

Set via environment:

```bash
CFLAGS="-O2 -Wall" CXXFLAGS="-O2 -Wall" meson setup builddir
```

Or via Meson options (preferred):

```bash
meson setup builddir -Dc_args="-O2 -Wall" -Dcpp_args="-O2 -Wall"
```

---

## 📚 8. Example `meson.build`

### C++ Example

```meson
project('cpp_app', 'cpp', default_options : ['cpp_std=c++20'])

executable('app', 'main.cpp')
```

### C Example

```meson
project('c_app', 'c')

executable('app', 'main.c')
```

---

## 🔍 9. Debugging & Compilation Database

Generate `compile_commands.json` (useful for clangd, IDEs):

```bash
meson setup builddir -Dbuildtype=debug
```

Meson generates it automatically in `builddir/`

---

## 🧩 10. Install

```bash
meson install -C builddir
```

Set custom prefix:

```bash
meson setup builddir --prefix=/usr/local
```

---

## 🔄 11. Updating After Source Changes

```bash
meson compile -C builddir
```

Meson auto-detects changes, no need to rerun setup unless configs change.

---

## 🧪 12. Advanced: Sanitizers (Clang Goodness)

```bash
meson setup builddir -Db_sanitize=address
```

Other options:

* `thread`
* `undefined`
* `memory`

---

## 🧭 13. Handy Ninja Shortcuts

```bash
ninja -C builddir -j$(nproc)   # parallel build
ninja -C builddir install      # install
ninja -C builddir test         # run tests
```

---

## 🧼 14. Full Reset Ritual

When things feel haunted:

```bash
rm -rf builddir
CC=clang CXX=clang++ meson setup builddir
meson compile -C builddir
```

---

## 🧾 15. Minimal Workflow Recap

```bash
CC=clang CXX=clang++ meson setup builddir
meson compile -C builddir
meson test -C builddir
```
