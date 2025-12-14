#include "sudoku.h"
#include <sstream>
#include <fstream>
#include <iostream>

Sudoku::Sudoku() {

}

Sudoku::~Sudoku() {

}

Sudoku::Sudoku(std::string f_name) {
    std::ifstream file(f_name);
    if (file.is_open()) {
        for (unsigned int row = 0; row < BOARD_SIZE; row++) {
            for (unsigned int col = 0; col < BOARD_SIZE; col++) {
                file >> board[row][col];
            }
        }
    }
    file.close();
}

bool Sudoku::solve() {
    for (unsigned int row = 0; row < BOARD_SIZE; row++) {
        for (unsigned int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == EMPTY) {
                for (unsigned int i = 1; i <= 9; i++) {
                    if (is_valid(row, col, i)) {
                        board[row][col] = i;
                        if (solve()) {
                            return true;
                        }
                        board[row][col] = EMPTY;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::is_valid(unsigned int row, unsigned int col, int num) {
    return (this->board)[row][col] == 0
            && !check_row(row, num)
            && !check_col(col, num)
            && !check_box(row - row % 3, col - col % 3, num);
}

bool Sudoku::check_row(unsigned int row, unsigned int num) {
    for (unsigned int col = 0; col < BOARD_SIZE; col++) {
        if (board[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool Sudoku::check_col(unsigned int col, unsigned int num) {
    for (unsigned int row = 0; row < BOARD_SIZE; row++) {
        if (board[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool Sudoku::check_box(unsigned int boxStartRow, unsigned int boxStartCol, unsigned int num) {
    for (unsigned int row = 0; row < 3; row++) {
        for (unsigned int col = 0; col < 3; col++) {
            if (board[boxStartRow + row][boxStartCol + col] == num) {
                return true;
            }
        }
    }
    return false;
}

void Sudoku::display_board() {
    for (unsigned int i = 0; i < this->BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < this->BOARD_SIZE; j++) {
            std::cout << (this->board)[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char *argv[]) {
    std::string f_name(argv[1]);

    Sudoku s(f_name);

    s.solve();

    s.display_board();

    return 0;
}

