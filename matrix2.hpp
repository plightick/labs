#ifndef MATRIX2_HPP
#define MATRIX2_HPP

#include <iostream>
#include <ostream>
#include <istream> 
class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    Matrix(int rows, int cols);
    ~Matrix();
    Matrix(const Matrix& other);

    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    
    Matrix(Matrix&& other) noexcept;
    Matrix& operator=(Matrix&& other) noexcept;

    friend Matrix operator&(const Matrix& lhs, const Matrix& rhs) {
        if (lhs.cols != rhs.rows) {
            throw std::invalid_argument("Невозможно перемножить данные матрицы");
        }
        
        Matrix result(lhs.rows, rhs.cols);
        for (int i = 0; i < lhs.rows; i++) {
            for (int j = 0; j < rhs.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < lhs.cols; k++) {
                    result.data[i][j] += lhs.data[i][k] * rhs.data[k][j];
                }
            }
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, Matrix& matrix) {
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.cols; j++) {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        std::cout << "Введите матрицу " << matrix.rows << "x" << matrix.cols << ":" << std::endl;
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.cols; j++) {
                is >> matrix.data[i][j];
            }
        }
        return is;
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }
    int getElement(int row, int col) const { return data[row][col]; }
    void setElement(int row, int col, int value) const { data[row][col] = value; }
};

#endif 
