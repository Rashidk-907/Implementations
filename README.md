# 🚀 Custom STL-like Containers in C++

This project contains implementations of commonly used STL containers from scratch in C++, built from scratch without using any STL containers internally.

---

## 📦 Implemented Containers

### 🧱 MyArray<T, N>
- Fixed-size array (like `std::array`)
- Supports:
  - `at()`, `operator[]`, `fill()`
  - `front()`, `back()`
  - `begin()`, `end()`, `swap()`

### 🔗 MySLL<T> *(Singly Linked List)*
- Operations:
  - `insert`, `erase`, `reverse`
  - `search`, `clear`
  - `push_front`, `push_back`

### 🔁 MyDLL<T> *(Doubly Linked List)*
- Bi-directional traversal
- Operations:
  - `insert`, `erase`, `reverse`
  - `print_reverse`, `clear`, `contains`

### 🧃 MyDeque<T>
- Built using `MyDLL<T>` internally
- Operations:
  - `push_front`, `push_back`
  - `pop_front`, `pop_back`
  - `front`, `back`, `empty`, `size`, `clear`
  - `print()`, `print_reverse()`

### 📚 MyStack<T>, MyQueue<T>
- Implemented using custom linked lists
- Basic `push`, `pop`, `top` / `front`, `back`, `empty`, `size`

---

## 🔧 Planned Containers

- `MySet<T>`
- `MyMap<Key, Value>`
- `MyUnorderedSet<T>`
- `BitSet`

---
## 🧱 Project Structure
- Include/ — Contains all header files for STL-like container implementations
- Test/ — Contains C++ test files to validate each container

---
## 🎯 Why This?

> Rebuilding the STL piece by piece helps me deeply understand how each container works under the hood, and strengthens my system-level C++ fundamentals.
