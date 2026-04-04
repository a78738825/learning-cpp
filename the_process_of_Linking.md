Compilation gave you a pile of `.o` files, each one a self-contained island humming with machine code but full of unanswered questions like “where is `printf`?” or “who owns `square(int)`?”.
**Linking is where those questions get resolved.**

---

# 🔗 What *Linking* Is (C++)

Linking is the process of combining multiple **object files** and **libraries** into a final executable (or another library).

👉 Input:

```
main.o  utils.o  math.o
```

👉 Output:

```
a.out  (or app.exe)
```

---

# 🧠 Core Job of the Linker

The linker does two big things:

### 1️⃣ Symbol Resolution

It matches **uses** of things with their **definitions**.

Example:

```cpp
// main.cpp
int square(int);

int main() {
    return square(5);
}
```

```cpp
// math.cpp
int square(int x) {
    return x * x;
}
```

* `main.o` says: “I need `square(int)`”
* `math.o` says: “I provide `square(int)`”

The linker connects them like plugging a cable into the correct port.

---

### 2️⃣ Relocation

Even after compilation, addresses are not final.

The linker:

* Assigns **final memory locations**
* Fixes machine code so calls/jumps point to the correct addresses

Think of it as replacing placeholder coordinates with actual GPS locations.

---

# 🧩 Symbols: The Currency of Linking

A **symbol** is basically a name the linker cares about:

* Functions (`square`)
* Global variables (`counter`)

Each symbol is either:

| Type      | Meaning            |
| --------- | ------------------ |
| Defined   | “I implement this” |
| Undefined | “I need this”      |

The linker’s job is to match them perfectly.

---

# 📦 Object Files: What’s Inside

Each `.o` file contains:

* Machine code
* Symbol table
* Relocation info

Example idea:

```
main.o:
  needs → square
  defines → main

math.o:
  defines → square
```

---

# ❌ Linker Errors (Where Things Explode)

This is where many C++ headaches live.

## 1️⃣ Undefined Reference

```id="l4p9cf"
undefined reference to `square(int)`
```

Meaning:

* Something was declared
* But no definition was found

💥 Causes:

* Forgot to compile/link a file
* Function declared but not implemented
* Mismatched signatures

---

## 2️⃣ Multiple Definitions

```id="k7f2q1"
multiple definition of `counter`
```

Meaning:

* Same symbol defined in multiple object files

💥 Classic mistake:

```cpp
// bad.h
int counter = 0;  // ❌ included in multiple .cpp files
```

Each `.cpp` creates its own definition → linker rage

---

# 📚 Static vs External (Now It Clicks)

Remember `static` at global scope?

```cpp
static int secret = 42;
```

During linking:

* This symbol is **invisible to other object files**

So:

* No conflicts ✅
* No sharing ❌

It’s like giving a function a private phone number 📵

---

# 🧪 Static Libraries (.a / .lib)

A static library is just a **bundle of object files**.

```
libmath.a → contains math.o, trig.o, etc.
```

During linking:

* Only the **needed pieces** are extracted

📌 Important:

* Code becomes part of your final executable
* No dependency at runtime

---

# 🌐 Dynamic Libraries (.so / .dll)

These are shared libraries loaded at runtime.

During linking:

* The linker records: “this symbol lives elsewhere”

At runtime:

* The OS loads the library and resolves symbols

📌 Result:

* Smaller executable
* Shared memory across programs
* But introduces runtime dependency

---

# ⚙️ The Linking Command

Typical example:

```bash
g++ main.o math.o -o app
```

Or in one shot:

```bash
g++ main.cpp math.cpp -o app
```

(Behind the scenes: compile → link)

---

# 🧠 Mental Model

Imagine:

* Each `.o` file is a **city block** 🏙️
* Symbols are **roads with names**
* Some roads just end abruptly (“undefined”)

The linker is the urban planner:

* Connects roads across blocks
* Removes duplicates
* Ensures every route leads somewhere real

---

# 🚫 What Linking Does NOT Do

To keep boundaries clean:

Linking does NOT:

* Check syntax (already done)
* Understand high-level C++ logic
* Recompile code

It works at a lower level: symbols and addresses.

---

# ⚡ Why This Matters in Practice

Linking explains:

* Why missing `.cpp` files break builds
* Why header misuse causes duplicate symbols
* Why `static` and `extern` matter
* Why libraries must be linked explicitly
