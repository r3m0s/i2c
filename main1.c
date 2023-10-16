#include <stdio.h>
#include <stdbool.h>

#define ROWS 6
#define COLS 7

char board[ROWS][COLS];

void initBoard() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board[row][col] = ' ';
        }
    }
}

void printBoard() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("| %c ", board[row][col]);
        }
        printf("|\n");
    }
    printf("  1   2   3   4   5   6   7\n");
    printf("-----------------------------\n");
}

bool isMoveValid(int col) {
    return col >= 0 && col < COLS && board[0][col] == ' ';
}

void makeMove(int col, char player) {
    for (int row = ROWS - 1; row >= 0; row--) {
        if (board[row][col] == ' ') {
            board[row][col] = player;
            return;
        }
    }
}

bool checkWinner(char player) {
    // Check horizontally
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col <= COLS - 4; col++) {
            if (board[row][col] == player &&
                board[row][col + 1] == player &&
                board[row][col + 2] == player &&
                board[row][col + 3] == player) {
                return true;
            }
        }
    }

    // Check vertically
    for (int row = 0; row <= ROWS - 4; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == player &&
                board[row + 1][col] == player &&
                board[row + 2][col] == player &&
                board[row + 3][col] == player) {
                return true;
            }
        }
    }

    // Check diagonally (bottom-left to top-right)
    for (int row = 3; row < ROWS; row++) {
        for (int col = 0; col <= COLS - 4; col++) {
            if (board[row][col] == player &&
                board[row - 1][col + 1] == player &&
                board[row - 2][col + 2] == player &&
                board[row - 3][col + 3] == player) {
                return true;
            }
        }
    }

    // Check diagonally (top-left to bottom-right)
    for (int row = 0; row <= ROWS - 4; row++) {
        for (int col = 0; col <= COLS - 4; col++) {
            if (board[row][col] == player &&
                board[row + 1][col + 1] == player &&
                board[row + 2][col + 2] == player &&
                board[row + 3][col + 3] == player) {
                return true;
            }
        }
    }

    return false;
}

bool isBoardFull() {
    for (int col = 0; col < COLS; col++) {
        if (board[0][col] == ' ') {
            return false;
        }
    }
    return true;
}

int main() {
    initBoard();
    char currentPlayer = 'X';
    int col;
    
    printf("Willkommen bei Vier gewinnt!\n");
    printf("Spieler 1: X\n");
    printf("Spieler 2: O\n");
    
    while (1) {
        printBoard();
        
        do {
            printf("Spieler %c, wähle eine Spalte (1-7): ", currentPlayer);
            int input;
            if (scanf("%d", &input) == 1) {
                col = input - 1;  // Adjust to zero-based index
            } else {
                while (getchar() != '\n');  // Clear input buffer
                col = -1;  // Invalid input
            }
        } while (!isMoveValid(col));
        
        if (col == -1) {
            printf("Ungültige Eingabe. Bitte wähle eine Spalte von 1 bis 7.\n");
            continue;
        }
        
        makeMove(col, currentPlayer);
        
        if (checkWinner(currentPlayer)) {
            printBoard();
            printf("Spieler %c gewinnt!\n", currentPlayer);
            break;
        }
        
        if (isBoardFull()) {
            printBoard();
            printf("Unentschieden!\n");
            break;
        }
        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    
    return 0;
}
