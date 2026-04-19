# C++ Scope Resolution Operator (`::`)

## 📌 What is `::`?

The **scope resolution operator (`::`)** in C++ is used to specify **where a variable, function, or object belongs**.

It tells the compiler:
> "Look in this specific scope to find this name."

---

## 🧠 Why do we need it?

In C++, different parts of a program can have the **same names**.

For example:
- A variable inside a function
- A variable in global scope
- A member inside a class

The `::` operator helps remove confusion by giving a **full address**.

---

## 🧩 Common Uses

### 1. With Namespaces

```cpp
#include <iostream>

int main() {
    std::cout << "Hello" << std::endl;
}
````

* `std` = namespace
* `cout` and `endl` belong to it

👉 `std::cout` means: use `cout` from the `std` namespace

---

### 2. With Classes (Static Members)

```cpp
class MyClass {
public:
    static int value;
};

int MyClass::value = 10;
```

* `value` belongs to `MyClass`
* `MyClass::value` tells the compiler where it is defined

---

### 3. Defining Member Functions Outside a Class

```cpp
class Dog {
public:
    void bark();
};

void Dog::bark() {
    std::cout << "Woof!" << std::endl;
}
```

👉 `Dog::bark` means the function belongs to the `Dog` class

---

### 4. With `enum class`

```cpp
enum class Color {
    RED,
    GREEN,
    BLUE
};

Color c = Color::GREEN;
```

👉 `Color::GREEN` specifies that `GREEN` is inside `Color`

---

### 5. Accessing Global Variables

```cpp
int x = 100; // global

int main() {
    int x = 50; // local

    std::cout << x << std::endl;   // 50
    std::cout << ::x << std::endl; // 100
}
```

👉 `::x` refers to the **global version** of `x`

---

## 🏗️ Mental Model

Think of C++ like a building:

* Namespace = floor
* Class = room
* Variables/functions = objects inside

`::` gives the full address:

```
Namespace::Class::Member
```

---

## ⚡ Summary

* `::` is the **scope resolution operator**
* It tells the compiler **exactly where to look**
* Used with:

  * Namespaces → `std::cout`
  * Classes → `MyClass::value`
  * Functions → `Dog::bark()`
  * Enums → `Color::GREEN`
  * Global scope → `::x`

---

## ✅ Key Takeaway

Without `::`, C++ might get confused between similar names.
With `::`, you remove ambiguity and write clearer, safer code.
