#ifndef MATRIX_HPP
#define MATRIX_HPP
 
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

    int getRows() const { return rows; }
    int getCols() const { return cols; }
    int getElement(int row, int col) const { return data[row][col]; }
    void setElement(int row, int col, int value) const { data[row][col] = value; }
};

#endif 
