#include <iostream>
#include "include/MyVector.hpp"  

void test_basic_push_pop() {
    std::cout << "Testing push/pop... ";
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    if (vec.size() != 3 || vec[0] != 10 || vec[1] != 20 || vec[2] != 30) {
        std::cout << "Failed\n";
        return;
    }

    int popped = vec.pop_back();
    if (popped != 30 || vec.size() != 2) {
        std::cout << "Failed\n";
        return;
    }

    std::cout << "Passed\n";
}

void test_clear() {
    std::cout << "Testing clear... ";
    MyVector<int> vec = {1, 2, 3};
    vec.clear();

    if (vec.size() != 0) {
        std::cout << "Failed\n";
        return;
    }

    vec.push_back(42);
    if (vec.size() != 1 || vec[0] != 42) {
        std::cout << "Failed\n";
        return;
    }

    std::cout << "Passed\n";
}

void test_initializer_list() {
    std::cout << "Testing initializer list... ";
    MyVector<int> vec = {5, 6, 7};
    if (vec.size() == 3 && vec[0] == 5 && vec[1] == 6 && vec[2] == 7) {
        std::cout << "Passed\n";
    } else {
        std::cout << "Failed\n";
    }
}

void test_copy_constructor() {
    std::cout << "Testing copy constructor... ";
    MyVector<int> a = {1, 2, 3};
    MyVector<int> b = a;

    bool same = (b.size() == a.size());
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) same = false;
    }

    b[0] = 99;
    if (!same || a[0] == 99) {
        std::cout << "Failed\n";
        return;
    }

    std::cout << "Passed\n";
}

void test_bounds_checking() {
    std::cout << "Testing bounds checking... ";
    MyVector<int> vec = {1, 2, 3};
    bool passed = false;

    try {
        int x = vec[-1];
    } catch (...) {
        passed = true;
    }

    try {
        int y = vec[3];
    } catch (...) {
        passed &= true;
    }

    MyVector<int> empty;
    try {
        empty.pop_back();
    } catch (...) {
        passed &= true;
    }

    std::cout << (passed ? "Passed\n" : "Failed\n");
}

void test_range_loop() {
    std::cout << "Testing range loop... ";
    MyVector<int> vec = {10, 20, 30};
    int sum = 0;

    for (int val : vec) {
        sum += val;
    }

    if (sum == 60) {
        std::cout << "Passed\n";
    } else {
        std::cout << "Failed\n";
    }
}

void test_dynamic_growth() {
    std::cout << "Testing dynamic growth... ";
    MyVector<int> vec;
    for (int i = 0; i < 100; ++i) {
        vec.push_back(i);
    }

    bool correct = (vec.size() == 100);
    for (int i = 0; i < 100; ++i) {
        if (vec[i] != i) {
            correct = false;
            break;
        }
    }

    std::cout << (correct ? "Passed\n" : "Failed\n");
}

int main() {
    test_basic_push_pop();
    test_clear();
    test_initializer_list();
    test_copy_constructor();
    test_bounds_checking();
    test_range_loop();
    test_dynamic_growth();

    std::cout << "\nAll tests finished.\n";
    return 0;
}
