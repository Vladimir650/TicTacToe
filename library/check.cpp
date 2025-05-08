#include <iostream>
#include "check.hpp"

bool checkWin(char** field, int FieldSize, char symbol) {
    for (int i = 0; i < FieldSize; i++) {
        bool rowWin = true, colWin = true;
        for (int j = 0; j < FieldSize; j++) {
            if (field[i][j] != symbol) rowWin = false;
            if (field[j][i] != symbol) colWin = false;
        }
        if (rowWin || colWin) return true;
    }

    bool mainDiag = true, secDiag = true;
    for (int i = 0; i < FieldSize; i++) {
        if (field[i][i] != symbol) mainDiag = false;
        if (field[i][FieldSize - 1 - i] != symbol) secDiag = false;
    }
    return mainDiag || secDiag;
}