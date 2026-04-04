# 📘 `static` in C++ (Outside Class/Struct)

## 🧭 What “outside a class” means

This refers to using `static` at **global/namespace scope**, not inside a class or struct.

---

## 🔒 Core Idea: Internal Linkage

When you declare something `static` at global scope, it gains **internal linkage**.

👉 Translation:
It is **only visible within the current `.cpp` file** (translation unit).

---

## 🧱 Static Global Variables

### Syntax

```cpp
static int counter = 0;
```

### Behavior

* Exists for the **entire program lifetime**
* Accessible **only within the file it’s declared in**
* Not visible to other `.cpp` files, even with `extern`

### Why use it?

* Avoid **name collisions** across files
* Hide implementation details (basic encapsulation)

---

## ⚙️ Static Functions (Free Functions)

### Syntax

```cpp
static void helper() {
    // ...
}
```

### Behavior

* Callable **only inside the same file**
* Cannot be used from other translation units

### Why use it?

* Mark functions as **private to the file**
* Prevent accidental external use

---

## 🧪 Example

### File: `math_utils.cpp`

```cpp
static int secret = 42;

static int square(int x) {
    return x * x;
}

int public_function(int x) {
    return square(x) + secret;
}
```

### File: `main.cpp`

```cpp
extern int public_function(int);

int main() {
    return public_function(5); // ✅ OK
}
```

🚫 This would fail:

```cpp
extern int secret;   // ❌ Not accessible
extern int square(int); // ❌ Not accessible
```

---

## 🧠 Key Properties

| Feature    | Static (global scope) |
| ---------- | --------------------- |
| Linkage    | Internal              |
| Visibility | Current file only     |
| Lifetime   | Entire program        |
| Use case   | Encapsulation, safety |

---

## ⚖️ `static` vs `extern`

| Keyword  | Meaning                             |
| -------- | ----------------------------------- |
| `static` | Restrict visibility to current file |
| `extern` | Declare something defined elsewhere |

---

## 🆕 Modern Alternative: Anonymous Namespace

Instead of `static`, modern C++ often prefers:

```cpp
namespace {
    int secret = 42;

    int square(int x) {
        return x * x;
    }
}
```

### Why?

* Same effect: **internal linkage**
* Works better with more complex declarations
* Considered more idiomatic in modern C++

---

## ⚠️ Common Pitfalls

* ❌ Expecting `static` globals to be shared across files
* ❌ Forgetting each `.cpp` gets its **own copy**
* ❌ Confusing with `static` inside functions or classes (different behavior!)

---

## 🧩 Mental Model

Picture each `.cpp` file as its own island 🏝️
`static` builds fences around variables/functions so they **can’t leave the island**.
