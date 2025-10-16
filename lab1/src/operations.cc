#include "../headers/operations.hpp"
#include "../headers/matrix.hpp"
#include <iostream>
#include <span>
#include <ranges>
#include <algorithm>

using namespace std;

bool isElementInMatrix(const Matrix* matrix, int element) {
    int rows = matrix->getRows();
    int cols = matrix->getCols();
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix->getElement(i, j) == element) {
                return true;
            }
        }
    }
    return false;
}

bool isElementInArray(std::span<const int> array, int element) {
    return std::ranges::contains(array, element);
}

void resizeArray(int*& array, int& capacity) {
    capacity *= 2;
    auto temp = new int[capacity];
    for (int i = 0; i < capacity / 2; i++) {
        temp[i] = array[i];
    }
    delete[] array; 
    
    array = temp;
}

void addElementToArray(int*& array, int& count, int& capacity, int element) {
    if (count >= capacity) {
        resizeArray(array, capacity);
    }
    array[count] = element;
    count++;
}

int* compactArray(std::span<const int> array) {
    if (array.empty()) {
        return nullptr;
    }
    
    auto temp = new int[array.size()];
    for (size_t i = 0; i < array.size(); i++) {
        temp[i] = array[i];
    }
    return temp;
}

int* findIntersection(const Matrix* firstMatrix, const Matrix* secondMatrix, int& resultSize) {
    int* intersection = nullptr;
    int count = 0;
    int capacity = 128;
    intersection = new int[capacity];

    int rowsFirst = firstMatrix->getRows();
    int colsFirst = firstMatrix->getCols();

    for (int i = 0; i < rowsFirst; i++) {
        for (int j = 0; j < colsFirst; j++) {
            int currentElement = firstMatrix->getElement(i, j);
            
            if (isElementInMatrix(secondMatrix, currentElement) && 
                !isElementInArray(intersection, count, currentElement)) {
                addElementToArray(intersection, count, capacity, currentElement);
            }
        }
    }

    int* finalResult = compactArray(intersection, count);
    delete[] intersection;
    
    resultSize = count;
    return finalResult;
}

int* collectUniqueElementsFromMatrix(const Matrix* matrix, int*& array, int& count, int& capacity) {
    int rows = matrix->getRows();
    int cols = matrix->getCols();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int currentElement = matrix->getElement(i, j);
            
            if (!isElementInArray(array, count, currentElement)) {
                addElementToArray(array, count, capacity, currentElement);
            }
        }
    }
    return array;
}

int* findUnion(const Matrix* firstMatrix, const Matrix* secondMatrix, int& resultSize) {
    int* unionResult = nullptr;
    int count = 0;
    const int capacity = 128;
    unionResult = new int[capacity];

    collectUniqueElementsFromMatrix(firstMatrix, unionResult, count, capacity);
    collectUniqueElementsFromMatrix(secondMatrix, unionResult, count, capacity);

    int* finalResult = compactArray(unionResult, count);
    delete[] unionResult;
    
    resultSize = count;
    return finalResult;
}