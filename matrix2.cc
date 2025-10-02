#include "matrix2.hpp"
#include <algorithm>
#include <stdexcept>

Matrix::Matrix(int row, int col) : rows(row), cols(col), data(new int*[row]) {
    for (int i = 0; i < row; i++) {
        data[i] = new int[col]();
    }
}
 
Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(new int*[other.rows]) {
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];
        std::copy(other.data[i], other.data[i] + cols, data[i]);
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;

    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;

    rows = other.rows;
    cols = other.cols;
    data = new int*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];
        std::copy(other.data[i], other.data[i] + cols, data[i]);
    }

    return *this;
}

Matrix Matrix::operator&(const Matrix& other) const {
    if(cols != other.rows){
        throw invalid_argument("Невозможно перемножить данные матрицы");
    }
    
    Matrix result(rows, other.cols);
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < other.cols; j++) {
            result.data[i][j] = 0;
            for(int k = 0; k < cols; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    
    return result;
}