# 🧠 What *Compilation* Really Is (C++)

Compilation is the process of transforming **a single source file** (`.cpp`) into an **object file** (`.o` / `.obj`).

Important boundary:

* ✅ Compilation: *one file at a time*
* ❌ No connecting to other files (that’s linking later)

---

# 🔬 The Stages of Compilation

Your code doesn’t go straight from C++ to machine code. It passes through a pipeline that looks like a slightly obsessive assembly line.

## 1️⃣ Preprocessing (Text Surgery)

Before “real” compilation even begins, the **preprocessor** rewrites your file.

### It handles:

* `#include` → literally pastes file contents
* `#define` → macro substitution
* `#if`, `#ifdef` → conditional compilation
* Removes comments

### Example

```cpp
#include <iostream>
#define SIZE 10
```

Becomes something like:

```cpp
// contents of iostream pasted here

int arr[10];
```

📌 At this stage:

* No types
* No syntax checking
* Just raw text manipulation

---

## 2️⃣ Lexical Analysis (Tokenization)

Now the compiler reads the text and breaks it into **tokens**.

```cpp
int x = 5;
```

Becomes:

```
[int] [identifier:x] [=] [literal:5] [;]
```

Think of it as turning a sentence into labeled word pieces.

---

## 3️⃣ Parsing (Syntax Tree Construction)

The compiler builds a structure called an **Abstract Syntax Tree (AST)**.

Your code:

```cpp
x = a + b;
```

Becomes something like:

```
   =
  / \
 x   +
    / \
   a   b
```

📌 Now the compiler understands *structure*, not just words.

---

## 4️⃣ Semantic Analysis (Meaning Check)

This is where the compiler starts asking tough questions:

* Is `x` declared?
* Are types compatible?
* Does this function exist?
* Are you breaking any language rules?

### Example errors caught here:

```cpp
int x = "hello";   // ❌ type mismatch
y = 10;            // ❌ undeclared variable
```

📌 This stage enforces the *rules of C++*.

---

## 5️⃣ Optimization (Optional but Powerful)

The compiler may rewrite your code to make it:

* Faster
* Smaller
* More efficient

### Example:

```cpp
int x = 2 * 3;
```

Might become:

```cpp
int x = 6;
```

Or even removed entirely if unused.

Other tricks include:

* Inlining functions
* Removing dead code
* Loop optimizations

📌 Important: Optimization does **not** change program behavior (in theory 😄)

---

## 6️⃣ Code Generation (Machine Code Creation)

Finally, the compiler produces **assembly**, then converts it into **machine code**.

Output:

```
file.o   (object file)
```

This file contains:

* Machine instructions
* Symbol table (names of functions/variables)
* Relocation info (used later by linker 👀)

---

# 📦 What You Get After Compilation

Each `.cpp` file becomes:

```
main.cpp  →  main.o
utils.cpp →  utils.o
```

These `.o` files are:

* Not runnable ❌
* Not complete ❌
* Missing connections ❌

They are like **isolated puzzle pieces**.

---

# 🧩 Translation Units

A key concept:

> A **translation unit** = one `.cpp` file after preprocessing

So:

```cpp
#include "a.h"
#include "b.h"
```

Becomes one giant file before compilation begins.

Each translation unit is compiled **independently**.

---

# ⚠️ Why This Matters (Big Picture)

This explains a lot of “weird” C++ behavior:

### 🔹 `static` at global scope

Each `.cpp` gets its own copy because it’s compiled separately.

### 🔹 Header files

Headers are pasted into multiple translation units, not shared magically.

### 🔹 Duplicate definitions

You can accidentally define the same thing in multiple `.cpp` files because they don’t see each other during compilation.

---

# 🧠 Mental Model

Imagine:

* Each `.cpp` file is sealed in a soundproof room 🎧
* The compiler works on one room at a time
* It produces a **machine-code fragment**
* No room knows what’s happening in another

Only later (linking) do the rooms connect doors.

---

# 🚫 What Compilation Does *NOT* Do

Let’s keep the boundary sharp:

Compilation does NOT:

* Combine multiple `.o` files
* Resolve cross-file function calls
* Produce an executable

That’s all **linking’s job**.
