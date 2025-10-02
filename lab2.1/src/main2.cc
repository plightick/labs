#include "../header/matrix2.hpp"
#include "../header/operations2.hpp"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    Matrix* firstMatrix = nullptr;
    Matrix* secondMatrix = nullptr;
    Matrix* resultMatrix = nullptr;

    bool running = true;
    while (running) {
        showMenu();
        int choice = checkInt();

        switch (choice) {
            case 1: inputFirstMatrix(firstMatrix); break;
            case 2: inputSecondMatrix(secondMatrix); break;
            case 3: printMatrices(firstMatrix, secondMatrix); break;
            case 4: multiplyMatrices(firstMatrix, secondMatrix, resultMatrix); break;
            case 0: running = false; break;
            default: cout << "Некорректный пункт меню.\n";
        }
    }

    delete firstMatrix;
    delete secondMatrix;
    delete resultMatrix;

    cout << "Завершение программы.\n";
    return 0;
}
