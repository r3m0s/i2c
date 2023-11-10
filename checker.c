#include <stdio.h>
#include <stdlib.h>

typedef enum { DiagonalDown=-6, DiagonalUp=-8, Horizontal=1, VerticalDown=-7 } Direction;
Direction directions[4] = { DiagonalDown, DiagonalUp, Horizontal, VerticalDown };

int checkState(int *column, char *board) {
    int originIndex = 0;

    // Finds index of the current game position (origin of evaluation)
    for(int i = 0; i < 6; i++) {
        if (board[(*column + (i * 7)) - 1] == ' ') {
            originIndex = (*column + ((i-1) * 7)) - 1;
            break;
        }

        // Set index to the highest value
        originIndex = (*column + (i * 7)) - 1;
    }

    for(int i = 0; i<4; ++i) {
        int identical = 0;
        int position = originIndex;

        if((directions[i]==DiagonalDown && originIndex%7 < 4) || (directions[i]==DiagonalUp && originIndex%7 > 2) || directions[i]==Horizontal || directions[i]==VerticalDown) {
            // Evaluate outer-most identical value going in one direction
            for(int l = originIndex; l >= 0 && l <= (6*7)-1 && board[l]==board[originIndex]; l+=directions[i]) {
                position = l;
            }

            // Evaluate identical values in a row starting at outer-most identical from before, going backwards
            for(int p = position; p >= 0 && p <= (6*7)-1 && board[p]==board[originIndex]; p-=directions[i]) {
                identical++;

                // Current player wins
                if(identical==4) {
                    return 1;
                }
            }
        }
    }

    // Return 0 if no winner
    return 0;
}