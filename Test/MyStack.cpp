#include <iostream>
#include "include/MyStack.hpp" 

int main()
{
    MyStack<int> st;
    std::cout << "Pushing 1, 2, 3...\n";
    st.push(1);
    st.push(2);
    st.push(3);

    std::cout << "Size: " << st.size() << "\n"; // 3
    std::cout << "Top: " << st.top() << "\n";   // 3

    std::cout << "Popping once...\n";
    st.pop();
    std::cout << "Top after pop: " << st.top() << "\n"; // 2

    std::cout << "Is empty? " << (st.empty() ? "Yes" : "No") << "\n"; // No

    std::cout << "Popping all...\n";
    st.pop();
    st.pop();

    std::cout << "Is empty? " << (st.empty() ? "Yes" : "No") << "\n"; // Yes

    // std::cout << "Try popping from empty stack (should handle gracefully)...\n";
    // st.pop(); 

    std::cout << "Pushing many elements to test resize...\n";
    for (int i = 0; i < 100; i++)
        st.push(i);

    std::cout << "Size after pushing 100 elements: " << st.size() << "\n";
    std::cout << "Top element now: " << st.top() << "\n"; // 99

    std::cout << "All tests complete.\n";
    return 0;
}
