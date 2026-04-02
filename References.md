# C++ References Explained

## What is a Reference?

A **reference** in C++ is an alias for another variable. Once a reference is initialized, it becomes another name for the same memory location.

```cpp
int x = 10;
int& ref = x;

ref = 20;
// x is now 20
````

* `ref` does not store its own value
* It directly refers to `x`

---

## Key Properties

* Must be initialized when declared
* Cannot be null
* Cannot be reseated (cannot refer to another variable later)

```cpp
int a = 5;
int& r = a;

// r = b; // This assigns value, NOT rebinding
```

---

## References vs Pointers

| Feature   | Reference     | Pointer        |
| --------- | ------------- | -------------- |
| Syntax    | `int& r = x;` | `int* p = &x;` |
| Null      | Not allowed   | Allowed        |
| Rebinding | Not allowed   | Allowed        |
| Access    | Direct        | Requires `*`   |

---

## Passing by Reference

References are commonly used to avoid copying data.

```cpp
void increment(int& value) {
    value++;
}

int main() {
    int x = 5;
    increment(x);
    // x is now 6
}
```

---

## Const References

Used to prevent modification while avoiding copies.

```cpp
void print(const int& value) {
    // value cannot be changed
}
```

Useful for large objects:

```cpp
#include <vector>

void printVector(const std::vector<int>& vec);
```

---

## Return by Reference

You can return references from functions.

```cpp
int& getElement(int arr[], int index) {
    return arr[index];
}

int main() {
    int arr[3] = {1, 2, 3};
    getElement(arr, 1) = 10;
    // arr[1] is now 10
}
```

---

## Reference to Temporary (const only)

```cpp
const int& r = 5;
```

This works because C++ creates a temporary and extends its lifetime.

---

## When to Use References

* Passing arguments efficiently
* Returning values without copying
* Creating cleaner syntax compared to pointers

---

## When NOT to Use

* When you need reseating (use pointers)
* When null is meaningful (use pointers)

---

## Summary

References are:

* Safer than pointers
* Cleaner syntax
* Widely used in function parameters

They are a fundamental tool for writing efficient and readable C++ code.
