#include <iostream>

template <typename T, int n>
class MyArray
{
private:
    T arr[n];
    int _size;

public:
    int size()
    {
        return _size;
    }
    const T &front()
    {
        return arr[0];
    }
    const T &back()
    {
        return arr[_size - 1];
    }

    void swap(MyArray<T, n> &other)
    {
        for (int i = 0; i < _size; i++)
        {
            std::swap(arr[i], other.arr[i]);
        }
    }

    T *begin() { return arr; }

    T *end() { return arr + _size; }

    bool empty()
    {
        return _size == 0;
    }

    const T &operator[](int index)
    {
        if (index < 0 || index >= n)
        {
            throw std::out_of_range("Accesing out of Bound");
        }
        return arr[index];
    }

    const T &at(int index)
    {
        if (index < 0 || index >= n)
        {
            throw std::out_of_range("Accesing out of Bound");
        }
        return arr[index];
    }

    void fill(T value)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = value;
        }
        _size = n;
    }
};