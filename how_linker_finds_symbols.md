# 🔗 How the Linker Finds Functions & Variables (C++)

## 🧠 The Core Problem

When you write:

```cpp
int square(int);  // declaration
```

…but define it in another file:

```cpp
int square(int x) { return x * x; }
```

👉 The compiler compiles files **independently**, so it cannot resolve this.

👉 The linker’s job is to **connect the declaration (use)** with the **definition**.

---

## 🧠 Step 1: What the Compiler Leaves Behind

When you write this:

```cpp
// main.cpp
int square(int);

int main() {
    return square(5);
}
```

The compiler produces `main.o` with:

* Machine code for `main`
* A note: **“I need `square(int)`”**

Internally, that becomes an **undefined symbol entry** in a symbol table:

```text
Symbol: square(int)
Type: undefined
```

---

## 🧾 Step 2: Every `.o` File Has a Symbol Table

Now consider:

```cpp
// math.cpp
int square(int x) {
    return x * x;
}
```

`math.o` contains:

```text
Symbol: square(int)
Type: defined
Address: (some offset)
```

---

## ⚙️ Step 3: The Linker Builds a Global Symbol Map

Here’s the key moment.

When the linker starts, it:

1. Reads **all object files**
2. Extracts their symbol tables
3. Builds a **global lookup structure**

Think:

```text
square(int)  →  defined in math.o
main         →  defined in main.o
```

This is typically implemented using **hash tables** for fast lookup
(not linear searching like a lost tourist wandering alleys)

---

## 🔍 Step 4: Resolving Symbols (Efficiently)

Now the linker processes undefined symbols:

From `main.o`:

```text
needs → square(int)
```

The linker:

1. Hashes `"square(int)"` (actually a mangled name, more on that soon)
2. Looks it up in the global symbol table
3. Finds:

   ```text
   → math.o provides it
   ```
4. Connects the call to the correct address

📌 This is basically **O(1)** lookup, not scanning every file repeatedly.

---

# 🧬 Name Mangling (Critical Detail)

C++ doesn’t actually store `square(int)` as plain text.

It encodes it into something like:

```text
_Z6squarei
```

This encodes:

* Function name
* Parameter types

Why?
Because of **function overloading**:

```cpp
int square(int);
double square(double);
```

These must become different symbols.

👉 The linker matches **mangled names**, not human-readable ones.

---

# 📦 What About Libraries?

Here’s where strategy gets interesting.

## Static Libraries (`.a` / `.lib`)

A static library is like a **box of `.o` files**.

The linker does NOT load everything.

Instead:

1. Sees an undefined symbol: `square`
2. Checks the library’s index (yes, it has one)
3. Pulls in **only the object file that defines it**

📌 Efficient because:

* Libraries include a **symbol index**
* No full scan required

---

## Dynamic Libraries (`.so` / `.dll`)

Different flow:

* Linker records: “this symbol will be resolved at runtime”
* Doesn’t need to find the actual code now

At runtime:

* The loader uses similar symbol lookup mechanisms

---

# ⚡ Order Matters (Subtle but Important)

With static libraries:

```bash
g++ main.o -lmath
```

works, but:

```bash
g++ -lmath main.o   // ❌ might fail
```

Why?

The linker processes left → right:

* It only pulls from a library when it already knows it needs something
* If it hasn’t seen the need yet, it skips it

So it’s not just efficient, it’s also a bit… procedural.

---

# 🧠 Mental Model

Picture the linker as:

* A librarian with a **perfect index system**
* Not reading every book
* Just jumping straight to the exact shelf using a coded label

Your undefined symbol is a request slip:

> “Bring me `_Z6squarei`”

The linker checks its master index and replies instantly:

> “Aisle math.o, row 3, slot 7.”

---

# 🚫 What It Does NOT Do

* It does NOT parse C++ again
* It does NOT understand “functions” semantically
* It does NOT scan files line by line

It operates purely on:

* Symbol names
* Tables
* Addresses

---

# 🧩 Tiny Summary

* Compiler → leaves **undefined + defined symbols**
* Linker → builds a **global symbol table (hashed)**
* Lookup → fast, not brute-force
* Matching → done via **mangled names**
* Libraries → use **indexes**, not blind searching
