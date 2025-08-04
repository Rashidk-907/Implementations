# 🚀 Custom STL-like Containers in C++

This project contains hand-written implementations of commonly used STL containers in C++, built from scratch without using any STL containers internally.

---

## 📦 Implemented Containers

- **MyArray<T, N>**
  - Fixed-size array (like `std::array`)
  - Supports `at()`, `operator[]`, `fill()`, `front()`, `back()`, `begin()`, `end()`, and `swap()`

- **MySLL<T>** *(Singly Linked List)*
  - `insert`, `erase`, `reverse`, `search`, `clear`, `push_front`, `push_back`

- **MyDLL<T>** *(Doubly Linked List)*
  - Bi-directional traversal, `insert`, `erase`, `reverse`, `print_reverse`, `clear`, `contains`

- **MyStack<T>**, **MyQueue<T>**
  - Implemented using custom linked lists

- **Planned:**
  - `MyDeque`, `MySet`, `MyMap`, `MyUnorderedSet`, `BitSet`

---

## 🎯 Why This?

> Rebuilding the STL piece by piece helps me deeply understand how each container works under the hood, and strengthens my system-level C++ fundamentals.

---

📁 Structure
MyArray.h – Static array

MyDLL.h, MySLL.h – Linked list implementations

MyStack.h, MyQueue.h – Basic containers using custom lists

tests/ – Small test cases for each

🙌 Contributions
Suggestions, improvements, and PRs are welcome — this is a learning-focused project!


