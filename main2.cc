#include "matrix2.hpp"
#include "operations2.hpp"
#include <iostream>

using namespace std;

int main() {
    Matrix* firstMatrix = nullptr;
    Matrix* secondMatrix = nullptr;
    Matrix* resultMatrix = nullptr;

    bool running = true;
    while (running) {
        showMenu();
        int choice = checkInt();

        switch (choice) {
            case 1: {
                cout << "Введите размеры первой матрицы (строки и столбцы): ";
                int rows = checkInt();
                int cols = checkInt();
                delete firstMatrix;
                firstMatrix = new Matrix(rows, cols);
                cin >> *firstMatrix;
                break;
            }
            case 2: {
                cout << "Введите размеры второй матрицы (строки и столбцы): ";
                int rows = checkInt();
                int cols = checkInt();
                delete secondMatrix;
                secondMatrix = new Matrix(rows, cols);
                cin >> *secondMatrix;
                break;
            }
            case 3: {
                cout << "Первая матрица:\n";
                if (firstMatrix) cout << *firstMatrix; else cout << "Не задана\n";
                cout << "Вторая матрица:\n";
                if (secondMatrix) cout << *secondMatrix; else cout << "Не задана\n";
                break;
            }
            case 4: {
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
                break;
            }
            case 0:
                running = false;
                break;
            default:
                cout << "Некорректный пункт меню.\n";
        }
    }

    delete firstMatrix;
    delete secondMatrix;
    delete resultMatrix;

    cout << "Завершение программы.\n";
    return 0;
}
