# 🧪 Clang Sanitizers Quick Guide (Meson Edition)

Sanitizers are like invisible gremlins that scream when your program steps on undefined behavior. Very helpful gremlins.

---

## ⚙️ 1. Enable a Sanitizer

```bash
meson setup builddir -Db_sanitize=address
```

Common values:

* `address` → memory errors (heap/stack corruption, use-after-free)
* `undefined` → UB (integer overflow, invalid shifts, etc.)
* `thread` → data races
* `memory` → uninitialized memory reads (Linux, special setup)

---

## 🧬 2. Combine Sanitizers

```bash
meson setup builddir -Db_sanitize=address,undefined
```

A popular combo:

```bash
-Db_sanitize=address,undefined
```

---

## 🧠 3. Recommended Debug Setup

```bash
meson setup builddir \
  -Dbuildtype=debug \
  -Db_sanitize=address,undefined
```

Why:

* Debug symbols make sanitizer reports readable
* Optimizations are reduced, fewer ghost bugs

---

## 🚀 4. Run Your Program

```bash
meson compile -C builddir
./builddir/your_executable
```

When something breaks, you’ll get a dramatic stack trace instead of silent chaos.

---

## 🧾 5. Example Output (ASan vibe)

```
==12345==ERROR: AddressSanitizer: heap-use-after-free
READ of size 4 at 0x...
    #0 main.cpp:42
```

Translation: your program touched memory that already retired from duty.

---

## 🧵 6. Thread Sanitizer

```bash
meson setup builddir -Db_sanitize=thread
```

Catches:

* race conditions
* unsynchronized shared state

⚠️ Slower than others, but brutally honest.

---

## 🧼 7. Clean Rebuild (Important!)

Switching sanitizers? Start fresh:

```bash
rm -rf builddir
meson setup builddir -Db_sanitize=address
```

Old builds can carry weird artifacts like a time traveler with baggage.

---

## 🧰 8. Extra Flags (Optional)

You can reinforce diagnostics:

```bash
meson setup builddir \
  -Db_sanitize=address \
  -Dc_args="-fno-omit-frame-pointer" \
  -Dcpp_args="-fno-omit-frame-pointer"
```

Helps produce cleaner stack traces.

---

## 🧪 9. Environment Tweaks (Advanced)

Control sanitizer behavior:

```bash
ASAN_OPTIONS=detect_leaks=1 ./builddir/app
```

Examples:

* `detect_leaks=1` → enable leak detection
* `halt_on_error=0` → keep running after errors

---

## 🧭 10. When to Use What

| Situation                     | Sanitizer   |
| ----------------------------- | ----------- |
| Random crashes                | `address`   |
| Weird logic / UB              | `undefined` |
| Multithreading bugs           | `thread`    |
| Suspicious uninitialized data | `memory`    |

---

## 🧪 11. Minimal Power Combo

```bash
meson setup builddir -Dbuildtype=debug -Db_sanitize=address,undefined
meson compile -C builddir
./builddir/app
```

---

## 🧩 12. Notes & Gotchas

* Sanitizers are mostly for **development**, not production
* `memory` sanitizer needs special libc builds on Linux
* `thread` sanitizer can conflict with `address`
* Expect slower runtime. Think microscope, not race car
