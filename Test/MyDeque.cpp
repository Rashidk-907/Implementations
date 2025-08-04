#include "MyDeque.hpp" // Make sure this includes MyDll too

int main()
{
    MyDeque<int> dq;

    std::cout << "Initial deque (should be empty): ";
    dq.print();

    std::cout << "\nPush back 10, 20, 30:\n";
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.print(); // Expected: 10->20->30->

    std::cout << "\nPush front 5:\n";
    dq.push_front(5);
    dq.print(); // Expected: 5->10->20->30->

    std::cout << "\nFront: " << dq.front() << ", Back: " << dq.back() << "\n"; // 5, 30

    std::cout << "\nPop front:\n";
    dq.pop_front();
    dq.print(); // Expected: 10->20->30->

    std::cout << "\nPop back:\n";
    dq.pop_back();
    dq.print(); // Expected: 10->20->

    std::cout << "\nClear deque:\n";
    dq.clear();
    dq.print(); // Should print nothing

    std::cout << "\nIs deque empty? " << (dq.empty() ? "Yes" : "No") << "\n";

    return 0;
}
