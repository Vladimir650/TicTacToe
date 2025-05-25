#include "library/board.hpp"
#include "library/board.cpp"
#include "library/check.hpp"
#include "library/check.cpp"

#include <iostream>
#include <limits>
#include <string>
#include <vector>

int main(){

    int menu = 0;

    while (true)
    {

        if (menu == 0)
        {
            std::cout << "     ~MENU~" << std::endl;
            std::cout << "1-Start the game" << std::endl;
            std::cout << "2-Parameters" << std::endl;
            std::cout << "3-History of games" << std::endl;
            std::cout << "4-Exit" << std::endl;

            int select;
            std::cin >> select;

            switch (select) {
                case 1:
                    menu += 1;
                    break;
                case 2:
                    menu += 2;
                    break;
                case 3:
                    menu += 3;
                    break;
                case 4:
                    std::cout << "Completion of the program. Goodbye!" << std::endl;
                    return 0;
                default:
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                    std::cout << "Invalid input. Please enter a number from 1 to 4." << std::endl;
                    continue;  
            }
        }

        if (menu == 1)
        {
            std::string player1;
            std::string player2;
            int FieldSize;

            std::cout << "Enter the name of the first player (cross):" << std::endl;
            std::cin >> player1;
            std::cout << "Eenter the name of the second player (zero):" << std::endl;
            std::cin >> player2;

            while (true) {
                std::cout << "Enter the field size (at least 3): ";
                std::cin >> FieldSize;
                if (FieldSize >= 3) break;
                std::cout << "Invalid size. Please enter a number 3 or higher.\n";
            }

            char** field = new char*[FieldSize];
            for (int i = 0; i < FieldSize; i++) {
                field[i] = new char[FieldSize];
                for (int j = 0; j < FieldSize; j++) {
                    field[i][j] = ' ';  
                }
            }

            std::cout << "Who will start? (1 - " << player1 << ", 2 - " << player2 << "): ";
            int firstPlayer;
            std::cin >> firstPlayer;

            std::string currentPlayer = (firstPlayer == 1) ? player1 : player2;
            char currentSymbol = 'X';

            CreateBoard(field, FieldSize);

            while (true) {

                int row, col;

                while (true) {
                    std::cout << currentPlayer << " (" << currentSymbol << "), enter row and column (e.g., 1 1): ";
                    std::cin >> row >> col;

                    if (std::cin.fail() || row < 1 || row > FieldSize || col < 1 || col > FieldSize) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Enter numbers within the field size.\n";
                        continue;
                    }

                    if (field[row - 1][col - 1] == ' ') {
                        field[row - 1][col - 1] = currentSymbol;
                        break;
                    } else {
                        std::cout << "This cell is already taken. Try again.\n";
                    }
                }

                CreateBoard(field, FieldSize);

                if (checkWin(field, FieldSize, currentSymbol)) {
                    std::cout << "Congratulations! " << currentPlayer << " wins!\n";
                    break;
                }

                currentPlayer = (currentPlayer == player1) ? player2 : player1;
                currentSymbol = (currentSymbol == 'X') ? 'O' : 'X';

            }
        }

        else if (menu == 2) {
            std::cout << "Parameters submenu - press any key to return..." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            menu = 0;
        }

        else if (menu == 3) {
            std::cout << "History submenu - press any key to return..." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            menu = 0;
        }

        char c;
        std::cin >> c;
        if (c == 27) {  
            menu = 0;
        }

    }

    return 0;
}