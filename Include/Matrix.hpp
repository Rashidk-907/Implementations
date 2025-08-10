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
    // * Constructors
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

    Matrix(initializer_list<initializer_list<T>> init)
    {
        row = init.size();
        col = init.begin()->size();
        data.reserve(row);
        for (auto &r : init)
        {
            data.emplace_back(r);
        }
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

    // * Arithmetic Operations and overloading
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

    void Scalar_Addition(T k)
    {
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                data[i][j] += k;
            }
        }
    }

    void Scalar_Subtraction(T k)
    {
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                data[i][j] -= k;
            }
        }
    }

    void Scalar_Division(T k)
    {
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                data[i][j] /= k;
            }
        }
    }

    // *Transformations
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

    void rotate_90()
    {
        transpose();
        int s = 0, e = col - 1;
        while (s < e)
        {
            for (int i = 0; i < row; i++)
            {
                swap(data[i][s], data[i][e]);
            }
            s++, e--;
        }
    }

    void rotate_180()
    {
        rotate_90();
        rotate_90();
    }

    void rotate_270()
    {
        rotate_90();
        rotate_90();
        rotate_90();
    }

    void rotate_k_times(int k)
    {
        k = k % 4;
        while (k--)
        {
            rotate_90();
        }
    }

    void flip_vertical()
    {
        int s = 0, e = col - 1;
        while (s < e)
        {
            for (int i = 0; i < row; i++)
            {
                swap(data[i][s], data[i][e]);
            }
            s++, e--;
        }
    }

    void flip_horizontal()
    {
        int s = 0, e = row - 1;
        while (s < e)
        {
            for (int i = 0; i < col; i++)
            {
                swap(data[s][i], data[e][i]);
            }
            s++, e--;
        }
    }

    // *Utilities
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

    int getRows() const { return row; }

    int getCols() const { return col; }

    void resize(size_t r, size_t c)
    {
        data.resize(r, vector<T>(c, T()));
    }

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

    void fill(T value)
    {
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                data[i][j] = value;
            }
        }
    }

    bool is_square()
    {
        return row == col;
    }

    void clear()
    {
        fill(0);
    }

    // *Searching

    pair<int, int> search(T value)
    {
        int s = 0, e = row * col;
        int mid = 0;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            int element = data[mid / col][mid % col];
            if (element == value)
            {
                return {mid / col, mid % col};
            }
            else if (element > value)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return {-1,-1};
    }

    void replace(T value, T change)
    {
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                if (data[i][j] == value)
                {
                    data[i][j] = change;
                }
            }
        }
    }

    double row_sum(size_t r)
    {
        double sum = 0;
        for (int i = 0; i < col; i++)
        {
            sum += data[r][i];
        }
        return sum;
    }

    double col_sum(size_t c)
    {
        double sum = 0;
        for (int i = 0; i < row; i++)
        {
            sum += data[i][c];
        }
        return sum;
    }

    T minimum()
    {
        T maxi = INT_MAX;
        for (const auto &row : data)
        {
            for (const auto &val : row)
                maxi = min(maxi, val);
        }
        return maxi;
    }

    T maximum()
    {
        T mini = INT_MIN;
        for (const auto &row : data)
        {
            for (const auto &val : row)
                mini = max(mini, val);
        }
        return mini;
    }
};
