#include <iostream>

template <typename T>
class MyStack
{
private:
    MyVector<T> arr;
    int _top; // Index of next insertion (also represents size)

public:
    mystack()
    {
        _top = 0;
    }

    inline void push(T data)
    {
        arr.push_back(data);
    }

    T top()
    {
        if (_top == 0)
        {
            std::cerr << "Warning: Stack is empty. No top element.\n";
            return T(); // Return default value if stack is empty
        }
        return arr[_top - 1];
    }

    bool empty()
    {
        return _top == 0;
    }

    void pop()
    {
        if (empty())
        {
            std::cerr << "Warning: Tried to pop from empty stack\n";
            return;
        }
        arr.push_back();
    }

    int size()
    {
        return _top;
    }
};
