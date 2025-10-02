#ifndef MATRIX2_HPP
#define MATRIX2_HPP

#include <iostream>
#include <ostream>
#include <istream>

using namespace std;
 
class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    Matrix(int rows, int cols);
    ~Matrix();
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    Matrix operator&(const Matrix& other) const;

    friend std::ostream& operator<<(ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            os << matrix.data[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

    friend std::istream& operator>>(istream& is, Matrix& matrix) {
    cout << "Enter matrix " << matrix.rows << "x" << matrix.cols << ":" << endl;
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
