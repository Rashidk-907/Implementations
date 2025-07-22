#include "include/MyQueue.hpp"

int main()
{
    myqueue<int> q;

    std::cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << "\n";

    std::cout << "Trying to pop from empty queue...\n";
    q.pop();

    std::cout << "Pushing 10, 20, 30 into queue...\n";
    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Front element: " << q.front() << "\n"; // 10
    std::cout << "Back element: " << q.back() << "\n";   //  30
    std::cout << "Current size: " << q.size() << "\n";   //  3

    std::cout << "Queue contents: ";
    q.print(); // 10 20 30

    std::cout << "Popping one element...\n";
    q.pop();

    std::cout << "Front element after pop: " << q.front() << "\n"; //  20
    std::cout << "Current size: " << q.size() << "\n";             //  2

    std::cout << "Popping all elements...\n";
    q.pop();
    q.pop();

    std::cout << "Is queue empty now? " << (q.empty() ? "Yes" : "No") << "\n";

    std::cout << "Trying front/back on empty queue...\n";
    q.front(); // print warning
    q.back();  // print warning

    std::cout << "Pushing 100 elements to test long run...\n";
    for (int i = 0; i < 100; i++)
        q.push(i);

    std::cout << "Current size: " << q.size() << "\n"; // 100
    std::cout << "Front: " << q.front() << ", Back: " << q.back() << "\n";

    std::cout << "Queue test complete.\n";

    return 0;
}