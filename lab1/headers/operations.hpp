#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP


#include "matrix.hpp"

int* findIntersection(Matrix* firstMatrix, Matrix* secondMatrix, int& resultSize);
int* collectUniqueElementsFromMatrix(const Matrix* matrix, int*& array, int& count, int& capacity);
int* compactArray(int* array, int count);
void addElementToArray(int*& array, int& count, int& capacity, int element);
void resizeArray(int*& array, int& capacity);
bool isElementInArray(const int* array, int size, int element);
bool isElementInMatrix(const Matrix* matrix, int element) ;
int* findUnion(Matrix* firstMatrix, Matrix* secondMatrix, int& resultSize);

#endif 
