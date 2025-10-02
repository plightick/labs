#include <iostream>
#include "../headers/menu.hpp"
#include "inputFunctions.hpp"

using namespace std;
 
int main() {
    Matrix* firstMatrix = nullptr;
    Matrix* secondMatrix = nullptr;

    int choice = 0;
    
    while (choice != 6) {
        displayMenu();
        choice = checkInt();
        processMenuChoice(choice, firstMatrix, secondMatrix);
    }
    
    delete firstMatrix;
    delete secondMatrix;
    return 0;
}