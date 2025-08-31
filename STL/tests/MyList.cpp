#include "include/MyList.hpp"

using std::cout;

int main()
{
    MyList<int> l;

    cout << "Inserting at head and tail...\n";
    l.insert_at_head(10);
    l.insert_at_tail(20);
    l.insert_at_tail(30);
    l.insert_at_head(5);
    l.print(); // Expected: 5->10->20->30->

    cout << "Insert at middle (pos 2, val 15)...\n";
    l.insert_at_middle(2, 15);
    l.print(); // Expected: 5->10->15->20->30->

    cout << "Delete head...\n";
    l.delete_head();
    l.print(); // Expected: 10->15->20->30->

    cout << "Delete tail...\n";
    l.delete_tail();
    l.print(); // Expected: 10->15->20->

    cout << "Delete middle (val 15)...\n";
    l.delete_mid(15);
    l.print(); // Expected: 10->20->

    cout << "Check size: " << l.size() << "\n"; // Expected: 2

    cout << "Reverse list...\n";
    l.reverse();
    l.print(); // Expected: 20->10->

    cout << "Contains 10? " << (l.contains(10) ? "Yes" : "No") << "\n"; // Yes
    cout << "Contains 99? " << (l.contains(99) ? "Yes" : "No") << "\n"; // No

    cout << "Clear list...\n";
    l.clear();
    l.print(); // Expected: (nothing)

    cout << "Is empty? " << (l.empty() ? "Yes" : "No") << "\n"; // Yes
}