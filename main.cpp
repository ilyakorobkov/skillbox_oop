#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    int rows, cols;

public:
    // Конструктор
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(rows, std::vector<int>(cols, 0));
    }

    // Перегрузка оператора сложения
    Matrix operator+(const Matrix &other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Перегрузка оператора вычитания
    Matrix operator-(const Matrix &other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = this->data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // Перегрузка оператора умножения
    Matrix operator*(const Matrix &other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += this->data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Перегрузка оператора +=
    Matrix& operator+=(const Matrix &other) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                this->data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    // Перегрузка оператора -=
    Matrix& operator-=(const Matrix &other) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                this->data[i][j] -= other.data[i][j];
            }
        }
        return *this;
    }

    // Перегрузка оператора *= (умножение матрицы на число)
    Matrix& operator*=(int scalar) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                this->data[i][j] *= scalar;
            }
        }
        return *this;
    }

    // Перегрузка оператора ввода >>
    friend std::istream& operator>>(std::istream &is, Matrix &matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                is >> matrix.data[i][j];
            }
        }
        return is;
    }

    // Перегрузка оператора вывода <<
    friend std::ostream& operator<<(std::ostream &os, const Matrix &matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
};

int main() {
    Matrix mat1(2, 2);
    Matrix mat2(2, 2);

    std::cout << "Enter values for mat1 (2x2):" << std::endl;
    std::cin >> mat1;
    std::cout << "Enter values for mat2 (2x2):" << std::endl;
    std::cin >> mat2;

    Matrix sum = mat1 + mat2;
    Matrix diff = mat1 - mat2;
    Matrix product = mat1 * mat2;

    mat1 += mat2;
    mat1 -= mat2;
    mat1 *= 2;

    std::cout << "Sum of mat1 and mat2:\n" << sum;
    std::cout << "Difference of mat1 and mat2:\n" << diff;
    std::cout << "Product of mat1 and mat2:\n" << product;

    std::cout << "mat1 after += mat2:\n" << mat1;
    std::cout << "mat1 after -= mat2:\n" << mat1;
    std::cout << "mat1 after *= 2:\n" << mat1;

    return 0;
}
