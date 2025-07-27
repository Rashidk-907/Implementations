#include "Include\MyDll.hpp" // If you saved your class in this header file, include accordingly
using namespace std;

int main()
{
    MyDll<string> dll;

    cout << "Initial list (should be empty): ";
    dll.print();

    cout << "Push tail: A, B, C\n";
    dll.push_tail("A");
    dll.push_tail("B");
    dll.push_tail("C");
    dll.print(); // A->B->C->

    cout << "Push head: Z\n";
    dll.push_head("Z");
    dll.print(); // Z->A->B->C->

    cout << "Insert at position 2: X\n";
    dll.insert(2, "X");
    dll.print(); // Z->A->X->B->C->

    cout << "List in reverse:\n";
    dll.print_reverse(); // C<-B<-X<-A<-Z<-

    cout << "Pop head\n";
    dll.pop_head();
    dll.print(); // A->X->B->C->

    cout << "Pop tail\n";
    dll.pop_tail();
    dll.print(); // A->X->B->

    cout << "Erase value 'X'\n";
    dll.erase("X");
    dll.print(); // A->B->

    cout << "Contains 'B': " << dll.contains("B") << "\n"; // 1
    cout << "Contains 'X': " << dll.contains("X") << "\n"; // 0

    cout << "Head: " << dll.at_head() << ", Tail: " << dll.at_tail() << "\n"; // A, B
    cout << "List size: " << dll.size() << "\n";                              // 2

    cout << "Reversing the list...\n";
    dll.reverse();
    dll.print(); // B->A->

    cout << "Clearing the list...\n";
    dll.clear();
    dll.print(); // (empty)

    cout << "Is list empty? " << dll.empty() << "\n"; // 1

    return 0;
}
