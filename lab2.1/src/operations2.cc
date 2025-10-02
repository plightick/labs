#include <iostream>
#include <limits>
#include "../header/matrix2.hpp"
#include "../header/operations2.hpp"

using namespace std;

int checkInt() {
    int number;
    while (true) {
        if (cin >> number) {
            if (cin.peek() == '\n' || cin.peek() == EOF) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return number;
            } else {
                cout << "Ошибка. Введите число: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else {
            cout << "Ошибка. Введите число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void inputFirstMatrix(Matrix*& firstMatrix) {
    cout << "Введите размеры первой матрицы (строки и столбцы): ";
    int rows = checkInt();
    int cols = checkInt();
    delete firstMatrix;
    firstMatrix = new Matrix(rows, cols);
    cin >> *firstMatrix;
}

void inputSecondMatrix(Matrix*& secondMatrix) {
    cout << "Введите размеры второй матрицы (строки и столбцы): ";
    int rows = checkInt();
    int cols = checkInt();
    delete secondMatrix;
    secondMatrix = new Matrix(rows, cols);
    cin >> *secondMatrix;
}

void printMatrices(const Matrix* firstMatrix, const Matrix* secondMatrix) {
    cout << "Первая матрица:\n";
    if (firstMatrix) cout << firstMatrix; else cout << "Не задана\n";
    cout << "Вторая матрица:\n";
    if (secondMatrix) cout << secondMatrix; else cout << "Не задана\n";
}

void multiplyMatrices(const Matrix* firstMatrix, const Matrix* secondMatrix, Matrix*& resultMatrix) {
    if (firstMatrix && secondMatrix) {
        if (firstMatrix->getCols() == secondMatrix->getRows()) {
            delete resultMatrix;
            resultMatrix = new Matrix((*firstMatrix) & (*secondMatrix));
            cout << "Результат умножения:\n" << *resultMatrix;
        } else {
            cout << "Матрицы несовместимы для умножения.\n";
        }
    } else {
        cout << "Введите обе матрицы сначала.\n";
    }
}

void showMenu() {
    cout << "\n===== МЕНЮ =====\n";
    cout << "1. Ввести первую матрицу\n";
    cout << "2. Ввести вторую матрицу\n";
    cout << "3. Вывести матрицы\n";
    cout << "4. Перемножить матрицы\n";
    cout << "0. Выход\n";
    cout << "Выберите пункт: ";
}
