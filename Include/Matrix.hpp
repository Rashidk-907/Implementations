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

    int getRows() const { return row; }
    int getCols() const { return col; }

    T &operator()(size_t r, size_t c)
    {
        if (r >= row || c >= col)
        {
            throw std::out_of_range("Matrix indices out of range");
        }
        return data[r][c];
    }

    const T &operator()(size_t r, size_t c) const
    {
        if (r >= row || c >= col)
        {
            throw std::out_of_range("Matrix indices out of range");
        }
        return data[r][c];
    }

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

    void fill(T value)
    {
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                data[i][j] = k;
            }
        }
    }

    void rotate()
    {
        transpose();
        int s = 0, e = col;
        while (s < e)
        {
            for (int i = 0; i < row; i++)
            {
                swap(data[i][s++], data[i][e--]);
            }
        }
    }
};
