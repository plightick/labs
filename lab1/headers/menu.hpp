#ifndef MENU_HPP
#define MENU_HPP

#include "matrix.hpp"
 
void displayMenu();
void processMenuChoice(int choice, Matrix*& firstMatrix, Matrix*& secondMatrix);
void inputMatrixData(Matrix* matrix);
void handleCreateFirstMatrix(Matrix*& firstMatrix);
void handleCreateSecondMatrix(Matrix*& secondMatrix); 
void handleFindIntersection(Matrix* firstMatrix, Matrix* secondMatrix);
void handleFindUnion(Matrix* firstMatrix, Matrix* secondMatrix);
void handleViewMatrices(const Matrix* firstMatrix,const Matrix* secondMatrix);
void handleExit(Matrix*& firstMatrix, Matrix*& secondMatrix);

#endif 
