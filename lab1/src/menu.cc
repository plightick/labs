#include "../headers/menu.hpp"
#include "../headers/inputFunctions.hpp"
#include "../headers/operations.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;
 
void displayMenu() {
    cout << "\n=========================================" << endl;
    cout << "               ГЛАВНОЕ МЕНЮ" << endl;
    cout << "=========================================" << endl;
    cout << "1. Создать первую матрицу" << endl;
    cout << "2. Создать вторую матрицу" << endl;
    cout << "3. Найти пересечение элементов матриц" << endl;
    cout << "4. Найти объединение элементов матриц" << endl;
    cout << "5. Показать матрицы" << endl;
    cout << "6. Выход" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Выберите пункт меню: ";
}

void inputMatrixData(const Matrix* matrix) {
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < matrix->getRows(); i++) {
        for (int j = 0; j < matrix->getCols(); j++) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            int value = checkInt();
            matrix->setElement(i, j, value);
        }
    }
}

void handleCreateFirstMatrix(Matrix*& firstMatrix) {
    cout << "\n--- Создание первой матрицы ---" << endl;
    cout << "Введите количество строк: ";
    int rows = checkInt();
    while (rows <= 0) {
        cout << "Количество строк должно быть положительным. Введите снова: ";
        rows = checkInt();
    }

    cout << "Введите количество столбцов: ";
    int cols = checkInt();
    while (cols <= 0) {
        cout << "Количество столбцов должно быть положительным. Введите снова: ";
        cols = checkInt();
    }

    if (firstMatrix != nullptr) {
        delete firstMatrix;
    }

    firstMatrix = new Matrix(rows, cols);
    inputMatrixData(firstMatrix);
    cout << "✓ Первая матрица создана успешно!" << endl;
}

void handleCreateSecondMatrix(Matrix*& secondMatrix) {
    cout << "\n--- Создание второй матрицы ---" << endl;
    cout << "Введите количество строк: ";
    int rows = checkInt();
    while (rows <= 0) {
        cout << "Количество строк должно быть положительным. Введите снова: ";
        rows = checkInt();
    }

    cout << "Введите количество столбцов: ";
    int cols = checkInt();
    while (cols <= 0) {
        cout << "Количество столбцов должно быть положительным. Введите снова: ";
        cols = checkInt();
    }

    if (secondMatrix != nullptr) {
        delete secondMatrix;
    }

    secondMatrix = new Matrix(rows, cols);
    inputMatrixData(secondMatrix);
    cout << "✓ Вторая матрица создана успешно!" << endl;
}

void handleFindIntersection(Matrix* firstMatrix, Matrix* secondMatrix) {
    cout << "\n--- Поиск пересечения ---" << endl;
    if (firstMatrix == nullptr || secondMatrix == nullptr) {
        cout << "Ошибка: обе матрицы должны быть созданы!" << endl;
        if (firstMatrix == nullptr) cout << " - Первая матрица не создана" << endl;
        if (secondMatrix == nullptr) cout << " - Вторая матрица не создана" << endl;
        return;
    }

    int resultSize = 0;
    int* intersection = findIntersection(firstMatrix, secondMatrix, resultSize);

    if (resultSize > 0 && intersection != nullptr) {
        cout << "Найдено пересечение элементов (" << resultSize << " элементов):" << endl;
        cout << "Результат: ";
        for (int i = 0; i < resultSize; i++) {
            cout << intersection[i];
            if (i < resultSize - 1) cout << ", ";
        }
        cout << endl;
        delete[] intersection;
    } else {
        cout << "Пересечение элементов не найдено." << endl;
        cout << "Матрицы не содержат общих элементов." << endl;
    }
}

void handleFindUnion(Matrix* firstMatrix, Matrix* secondMatrix) {
    cout << "\n--- Поиск объединения ---" << endl;
    if (firstMatrix == nullptr || secondMatrix == nullptr) {
        cout << "Ошибка: обе матрицы должны быть созданы!" << endl;
        if (firstMatrix == nullptr) cout << " - Первая матрица не создана" << endl;
        if (secondMatrix == nullptr) cout << " - Вторая матрица не создана" << endl;
        return;
    }

    int resultSize = 0;
    int* unionResult = findUnion(firstMatrix, secondMatrix, resultSize);

    if (resultSize > 0 && unionResult != nullptr) {
        cout << "Найдено объединение элементов (" << resultSize << " уникальных элементов):" << endl;
        cout << "Результат: ";
        for (int i = 0; i < resultSize; i++) {
            cout << unionResult[i];
            if (i < resultSize - 1) cout << ", ";
        }
        cout << endl;
        delete[] unionResult;
    } else {
        cout << "Матрицы пусты." << endl;
    }
}

void handleViewMatrices(const Matrix* firstMatrix,const Matrix* secondMatrix) {
    cout << "\n--- Просмотр матриц ---" << endl;
    if (firstMatrix != nullptr) {
        cout << "Первая матрица (" << firstMatrix->getRows() << "x" << firstMatrix->getCols() << "):" << endl;
        for (int i = 0; i < firstMatrix->getRows(); i++) {
            for (int j = 0; j < firstMatrix->getCols(); j++) {
                cout << firstMatrix->getElement(i, j) << "\t";
            }
            cout << endl;
        }
    } else {
        cout << "Первая матрица не создана." << endl;
    }

    cout << endl;

    if (secondMatrix != nullptr) {
        cout << "Вторая матрица (" << secondMatrix->getRows() << "x" << secondMatrix->getCols() << "):" << endl;
        for (int i = 0; i < secondMatrix->getRows(); i++) {
            for (int j = 0; j < secondMatrix->getCols(); j++) {
                cout << secondMatrix->getElement(i, j) << "\t";
            }
            cout << endl;
        }
    } else {
        cout << "Вторая матрица не создана." << endl;
    }
}

void handleExit(Matrix*& firstMatrix, Matrix*& secondMatrix) {
    cout << "\n--- Выход ---" << endl;
    if (firstMatrix != nullptr) {
        delete firstMatrix;
        firstMatrix = nullptr;
        cout << "Память первой матрицы освобождена." << endl;
    }
    if (secondMatrix != nullptr) {
        delete secondMatrix;
        secondMatrix = nullptr;
        cout << "Память второй матрицы освобождена." << endl;
    }
    cout << "Программа завершена." << endl;
}

void processMenuChoice(int choice, Matrix*& firstMatrix, Matrix*& secondMatrix) {
    switch (choice) {
        case 1: handleCreateFirstMatrix(firstMatrix); break;
        case 2: handleCreateSecondMatrix(secondMatrix); break;
        case 3: handleFindIntersection(firstMatrix, secondMatrix); break;
        case 4: handleFindUnion(firstMatrix, secondMatrix); break;
        case 5: handleViewMatrices(firstMatrix, secondMatrix); break;
        case 6: handleExit(firstMatrix, secondMatrix); break;
        default: cout << "Неверный выбор. Попробуйте снова." << endl; break;
    }
}