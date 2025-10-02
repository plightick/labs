#ifndef OPERATIONS2_HPP
#define OPERATIONS2_HPP

#include "matrix2.hpp"

int checkInt();
void showMenu();

void inputFirstMatrix(Matrix*& firstMatrix);
void inputSecondMatrix(Matrix*& secondMatrix);
void printMatrices(const Matrix* firstMatrix, const Matrix* secondMatrix);
void multiplyMatrices(const Matrix* firstMatrix, const Matrix* secondMatrix, Matrix*& resultMatrix);

#endif
