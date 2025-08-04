#include "MyDll.hpp"

template <typename T>
class MyDeque
{
private:
    MyDll<T> dll; // Underlying container (doubly linked list)

public:
    // Insertions
    void push_front(T data) { dll.push_head(data); }
    void push_back(T data) { dll.push_tail(data); }

    // Removals
    void pop_front() { dll.pop_head(); }
    void pop_back() { dll.pop_tail(); }

    // Access
    T front() { return dll.at_head(); }
    T back() { return dll.at_tail(); }

    // Utility
    bool empty() { return dll.empty(); }
    int size() { return dll.size(); }
    void clear() { dll.clear(); }

    // Optional: Print for debugging
    void print() { dll.print(); }
    void print_reverse() { dll.print_reverse(); }
};