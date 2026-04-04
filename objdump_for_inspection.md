> `objdump` is like a forensic toolkit for compiled binaries. If your `.cpp` file becomes a sealed crate after compilation, `objdump` is the crowbar, flashlight, and magnifying glass all in one 🔍📦

> It lets you **inspect object files, executables, and libraries** at a very low level.

---

# 🛠️ What is `objdump`?

`objdump` is a command-line tool (part of GNU binutils) that can:

* Disassemble machine code → human-readable assembly
* Show symbol tables
* Display sections of object files
* Reveal how your compiled program actually looks internally

👉 It works on:

```text
.o   (object files)
a.out / .exe  (executables)
.a / .so      (libraries)
```

---

# 🧠 Why It Matters (in Your Context)

You were asking:

> how does the linker find symbols?

`objdump` lets you **see the exact symbols** the linker works with.

Not the friendly:

```cpp
square(int)
```

But the real thing:

```text
_Z6squarei
```

It’s like switching from a character’s nickname to their passport ID.

---

# 🔍 Useful `objdump` Commands

## 1️⃣ View Symbol Table

```bash
objdump -t file.o
```

Example output (simplified):

```text
00000000 g     F .text  00000014 _Z6squarei
00000014 g     F .text  00000020 main
```

### What this means:

* `_Z6squarei` → mangled name of `square(int)`
* `F` → function
* `.text` → code section
* Numbers → memory offsets

👉 This is exactly what the linker reads.

---

## 2️⃣ Disassemble Code

```bash
objdump -d file.o
```

Output:

```text
00000000 <_Z6squarei>:
   0:   imul   %edi,%edi
   3:   mov    %edi,%eax
   5:   ret
```

👉 This is your C++ function translated into assembly.

---

## 3️⃣ Show Everything (Firehose Mode)

```bash
objdump -x file.o
```

This dumps:

* Headers
* Sections
* Symbols
* Relocation info

It’s dense, but it’s the full anatomy.

---

# 🧬 Connecting Back to the Linker

When the linker runs, it effectively does:

1. Read symbol tables (like `objdump -t`)
2. Match:

   ```text
   undefined → defined
   ```
3. Use relocation info to patch addresses

So when you use `objdump`, you're peeking at:

> the exact database the linker queries

---

# 🆚 `objdump` vs `nm`

You might also see `nm`:

```bash
nm file.o
```

* `nm` → quick symbol list (lightweight)
* `objdump` → full inspection toolkit

Think:

* `nm` = index page 📖
* `objdump` = entire book with annotations 📚

---

# 🧠 Tiny Demo Flow

```bash
g++ -c main.cpp
g++ -c math.cpp
objdump -t main.o
objdump -t math.o
```

Now you can literally see:

* what `main.o` needs
* what `math.o` provides

…and mentally simulate the linker.

---

# 🧩 Mental Image

If linking is a matchmaking process 💌

* Symbol tables = profiles
* Mangled names = unique IDs
* Linker = algorithm
* `objdump` = admin panel showing all profiles raw
