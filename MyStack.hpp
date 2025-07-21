#include <iostream>

template <typename T>
class MyStack
{
private:
    T *arr;
    int _top;  // Index of next insertion (also represents size)
    int _cap;  // Current capacity of the array

public:
    MyStack()
    {
        arr = new T[2];
        _top = 0;
        _cap = 2;
    }

    void resize()
    {
        _cap *= 2;
        T *arr2 = new T[_cap];

        // Copy only the active elements
        for (int i = 0; i < _top; i++)
        {
            arr2[i] = arr[i];
        }

        delete[] arr;
        arr = arr2;
    }

    inline void push(T data)
    {
        if (_top == _cap)
        {
            resize();  // Double capacity when full
        }
        arr[_top++] = data;
    }

    T top()
    {
        if (_top == 0)
        {
            std::cerr << "Warning: Stack is empty. No top element.\n";
            return T();  // Return default value if stack is empty
        }
        return arr[_top - 1];
    }

    bool empty()
    {
        return _top == 0;
    }

    void pop()
    {
        if (_top == 0)
        {
            std::cerr << "Warning: Tried to pop from empty stack\n";
            return;
        }
        _top--;
    }

    int size()
    {
        return _top;
    }

    ~MyStack()
    {
        delete[] arr;
    }
};
