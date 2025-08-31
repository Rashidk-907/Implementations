#include "MyArray.hpp"

using namespace std;

void test_fill()
{
    MyArray<int, 5> arr;
    arr.fill(3);

    std::cout << "Test fill(): ";
    for (int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void test_accessors()
{
    MyArray<int, 4> arr;
    arr.fill(10);

    std::cout << "Front: " << arr.front() << "\n";
    std::cout << "Back: " << arr.back() << "\n";

    std::cout << "Using at(): " << arr.at(2) << "\n";

    try
    {
        arr.at(5); // Should throw
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Caught exception (at): " << e.what() << "\n";
    }
}

void test_swap()
{
    MyArray<int, 3> a1;
    MyArray<int, 3> a2;

    a1.fill(1);
    a2.fill(2);

    a1.swap(a2);

    std::cout << "After swap:\n";
    std::cout << "a1: ";
    for (int i = 0; i < a1.size(); ++i)
        std::cout << a1[i] << " ";
    std::cout << "\na2: ";
    for (int i = 0; i < a2.size(); ++i)
        std::cout << a2[i] << " ";
    std::cout << "\n";
}

void test_iteration()
{
    MyArray<int, 5> arr;
    arr.fill(9);

    std::cout << "Range-based iteration: ";
    for (int *ptr = arr.begin(); ptr != arr.end(); ++ptr)
        std::cout << *ptr << " ";
    std::cout << "\n";
}

int main()
{
    test_fill();
    test_accessors();
    test_swap();
    test_iteration();

    return 0;
}
