#include <iostream>
#include "board.hpp"

void CreateBoard(char** field, int FieldSize){

    std::cout << "\n";

    for (int i = 0; i < FieldSize; i++) { 
        for (int j = 0; j < FieldSize; j++) {
            std::cout << "| " << field[i][j] << " ";
        }
        std::cout << "|\n";

        if (i < FieldSize - 1) {
            for (int j = 0; j < FieldSize; j++) {
                std::cout << "+---";
            }
            std::cout << "+\n";
        }
    }
    std::cout << "\n";
}