#include <stdio.h>
#include <stdlib.h>

typedef enum { DiagonalDownForward=-6, DiagonalDownBackward=-8, Horizontal=1, VerticalDown=-7 } Direction;
Direction directions[4] = { DiagonalDownForward, DiagonalDownBackward, Horizontal, VerticalDown };

int checkState(int *column, char *board) {
    int originIndex = 0;

    // Finds index of the current game position (index of evaluation in the one dimensional array)
    for(int i = 0; i < 6; i++) {
        if (board[(*column + (i * 7)) - 1] == ' ') {
            originIndex = (*column + ((i-1) * 7)) - 1;
            break;
        }

        // Set index to the highest value
        originIndex = (*column + (i * 7)) - 1;
    }

    // Check in all directions from enumeration of directions (total of 4 directions)
    for(int i = 0; i<4; ++i) {
        // Set to initial values (origin of check to current array index number and amount of identical in arrow to 0)
        int identical = 0;
        int position = originIndex;
        int previousPosition = originIndex;

        // Checks if position is within the valid area (diagonal problem of jumping to left/right)
        // Evaluate outer-most identical value going in current directions steps and considering array boundaries
        for(int l = originIndex; l >= 0 && l <= (6*7)-1 && board[l]==board[originIndex]; l+=directions[i]) {
            // When going downwards in diagonal directions the checker must validate that there are no random jumps
            // This is done by comparing the remainders of the previous and current position
            // Diagonal Down Forward: Remainder of current must be greater than previous (remainder increases towards the right side of the board)
            // Diagonal Down Backward: Remainder of current must be less than previous (remainder decreases towards the left side of the board)
            if(
                (directions[i]==DiagonalDownForward && l%7 >= previousPosition%7) ||
                (directions[i]==DiagonalDownBackward && previousPosition%7 != 1 && l%7 <= previousPosition%7) ||
                (directions[i]==Horizontal && previousPosition%7 != 1) ||
                directions[i]==VerticalDown
                ) {
                position = l;
                previousPosition = l;
            }
        }

        // Evaluate identical values in a row starting at outer-most identical from before, going backwards in current directions steps
        for(int p = position; p >= 0 && p <= (6*7)-1 && board[p]==board[originIndex]; p-=directions[i]) {
            // When going upwards in diagonal directions the checker must validate that there are no random jumps
            // This is done by comparing the remainders of the previous and current position
            // Diagonal Down Forward: Remainder of current must be less or equal than previous (remainder decreases towards the left side of the board)
            // Diagonal Down Backward: Remainder of current must be greater or equal than previous (remainder increases towards the right side of the board)
            if(
                (directions[i]==DiagonalDownForward && p%7 <= previousPosition%7) ||
                (directions[i]==DiagonalDownBackward && previousPosition%7 != 0 && p%7 >= previousPosition%7) ||
                (directions[i]==Horizontal && previousPosition != 0) ||
                directions[i]==VerticalDown
                ) {
                identical++;
            }

            previousPosition = p;

            // Current player wins
            if(identical==4) {
                return 1;
            }
        }
    }

    // Return 0 if no winner
    return 0;
}
