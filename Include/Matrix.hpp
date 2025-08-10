#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Matrix
{
private:
    int row;
    int col;
    vector<vector<T>> data;

public:
    // Constructor
    Matrix(int r, int c)
    {
        if (r <= 0 || c <= 0)
        {
            throw std::invalid_argument("Matrix dimensions must be positive");
        }
        row = r;
        col = c;
        data.resize(row, vector<T>(col, T())); // initialize with default value of T
    }

    // Constructor from 2D vector
    Matrix(const vector<vector<T>> &input)
    {
        if (input.empty() || input[0].empty())
        {
            throw std::invalid_argument("Matrix dimensions cannot be zero");
        }
        row = input.size();
        col = input[0].size();
        data = input;
    }

    // Getters
    int getRows() const { return row; }
    int getCols() const { return col; }

    // Element access (non-const)
    T &operator()(size_t r, size_t c)
    {
        if (r >= row || c >= col)
        {
            throw std::out_of_range("Matrix indices out of range");
        }
        return data[r][c];
    }

    // Element access (const)
    const T &operator()(size_t r, size_t c) const
    {
        if (r >= row || c >= col)
        {
            throw std::out_of_range("Matrix indices out of range");
        }
        return data[r][c];
    }

    // Addition
    Matrix operator+(const Matrix &other) const
    {
        if (row != other.row || col != other.col)
        {
            throw std::invalid_argument("Matrix dimensions must match for addition");
        }
        Matrix<T> temp(row, col);
        for (size_t r = 0; r < row; r++)
        {
            for (size_t c = 0; c < col; c++)
            {
                temp(r, c) = data[r][c] + other(r, c);
            }
        }
        return temp;
    }

    // Subtraction
    Matrix operator-(const Matrix &other) const
    {
        if (row != other.row || col != other.col)
        {
            throw std::invalid_argument("Matrix dimensions must match for subtraction");
        }
        Matrix<T> temp(row, col);
        for (size_t r = 0; r < row; r++)
        {
            for (size_t c = 0; c < col; c++)
            {
                temp(r, c) = data[r][c] - other(r, c);
            }
        }
        return temp;
    }

    // Matrix multiplication
    Matrix operator*(const Matrix &other) const
    {
        if (col != other.row)
        {
            throw std::invalid_argument("Matrix multiplication dimension mismatch");
        }
        Matrix<T> temp(row, other.col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < other.col; j++)
            {
                for (int k = 0; k < col; k++)
                {
                    temp(i, j) += data[i][k] * other(k, j);
                }
            }
        }
        return temp;
    }

    // Scalar multiplication
    void Scalar_Multiplication(T k)
    {
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                data[i][j] *= k;
            }
        }
    }

    // Transpose (in-place for square matrix)
    void transpose()
    {
        if (row != col)
        {
            throw std::logic_error("In-place transpose only works for square matrices");
        }
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = i + 1; j < col; j++)
            {
                swap(data[i][j], data[j][i]);
            }
        }
    }

    // Print
    void print() const
    {
        for (const auto &row : data)
        {
            for (const auto &val : row)
                cout << val << " ";
            cout << "\n";
        }
        cout << "\n";
    }
};
