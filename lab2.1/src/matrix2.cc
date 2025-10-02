#include "../header/matrix2.hpp"
#include <algorithm>
#include <stdexcept>

using namespace std;

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

