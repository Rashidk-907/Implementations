#include "MyVector.hpp"

template <typename T>
class myqueue
{
private:
    MyVector<T> arr;
    int _front;
    int _back;
    int _size;

public:
    myqueue()
    {
        _front = 0;
        _back = -1;
        _size = 0;
    }
    void push(T data)
    {
        arr.push_back(data);
        _back++;
        _size++;
    }

    int size()
    {
        return (_back - _front) + 1;
    }

    T pop()
    {
        if (empty())
        {
            std::cout << "Queue is Empty\n";
            return -1;
        }

        return arr[_front++];
    }
    T front()
    {
        if (empty())
        {
            std::cout << "Queue is Empty\n";
            return -1;
        }

        return arr[_front];
    }
    T back()
    {
        if (empty())
        {
            std::cout << "Queue is Empty\n";
            return -1;
        }
        return arr[_back];
    }
    bool empty()
    {
        return _front > _back;
    }
    void print()
    {
        for (int i = _front; i < _back; i++)
        {
            std::cout << arr[i] << " ";
        }
    }
};