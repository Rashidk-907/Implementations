#include <iostream>

template <typename T>
class MyVector
{
private:
    T *arr;
    int _size;
    int _cap;

public:
    void resize()
    {
        _cap = _cap * 2;
        T *arr2 = new T[_cap];

        for (int i = 0; i < _size; i++)
        {
            arr2[i] = arr[i];
        }

        delete[] arr;
        arr = arr2;
    }

    MyVector(std::initializer_list<T> list)
    {
        _size = list.size();
        _cap = _size;
        arr = new T[_cap];

        int i = 0;
        for (T val : list)
            arr[i++] = val;
    }

    MyVector(int cap) : _cap(cap)
    {
        arr = new T[_cap];
        _size = 0;
    }

    MyVector()
    {
        _cap = 1;
        _size = 0;
        arr = new T[_cap];
    }

    // Copy constructor (deep copy)
    MyVector(const MyVector &myvector)
    {
        _size = myvector._size;
        _cap = myvector._cap;
        arr = new T[_cap];

        for (int i = 0; i < _size; i++)
        {
            arr[i] = myvector.arr[i];
        }
    }

    void push_back(T data)
    {
        if (_size == _cap)
        {
            resize();
        }

        arr[_size++] = data;
    }

    inline int size()
    {
        return _size;
    }

    int capacity()
    {
        return _cap;
    }

    ~MyVector()
    {
        delete[] arr;
    }

    void clear()
    {
        delete[] arr;
        _size = 0;
        _cap = 1;
        arr = new T[_cap];
    }

    T pop_back()
    {
        if (_size == 0)
            throw std::out_of_range("pop_back from empty vector");

        return arr[--_size];
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= _size)
        {
            throw std::out_of_range("index out of bound");
        }

        return arr[index];
    }

    T *begin() { return arr; }

    T *end() { return arr + _size; }
};
