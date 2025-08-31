#include "Matrix.hpp"

int main()
{
    Matrix<int> m1({{1, 2, 3}, {4, 5, 6}});
    cout << "Original:\n";
    m1.print();

    auto pos = m1.search(5);
    cout << "Found 5 at: (" << pos.first << ", " << pos.second << ")\n";

    m1.flip_vertical();
    cout << "After Vertical Flip:\n";
    m1.print();

    m1.flip_horizontal();
    cout << "After Horizontal Flip:\n";
    m1.print();

    m1.replace(5, 50);
    cout << "After replacing 5 with 50:\n";
    m1.print();

    cout << "Row 0 sum: " << m1.row_sum(0) << "\n";
    cout << "Col 1 sum: " << m1.col_sum(1) << "\n";
    cout << "Minimum value: " << m1.minimum() << "\n";
    cout << "Maximum value: " << m1.maximum() << "\n";

    return 0;
}