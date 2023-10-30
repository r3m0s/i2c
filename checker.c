//
// Created by remo on 13.10.2023.
//

#include <stdio.h>
#include <stdlib.h>

enum Direction {DiagonalDown=-6, DiagonalUp=-8, Horizontal=1, VerticalDown=-7};

int checkState(char *a) {
    for (int i = 5; i >= 0; i--) {

    }
  return 0;
}

int countTowardsCenter() {
    int counter = 0;

    return counter;
}

void findOpponentInsideOut(char** array, int r) {
    // iterate over rows
    for (int y = 0; y <= r; y++) {
        // iterate over columns
        for (int x = 0; x <= r; x++) {
            // only do checks in the circles/rects
            if (y % r == 0 || x % r == 0) {
                // leave out check above new symbol
                if (x % r != r/2 || y == r) {
                    // leave out checks where the grid does not fall into consideration in outer rounds (not vertically/horizontally/diagonally reachable)
                    if (x % (r/2) == 0 && y % (r/2) == 0) {
                        // find first symbol of opponent and start to count back towards center
                        printf("x");
                        if(*(*(array + y) + x) == 'o') {
                            countTowardsCenter();
                        }
                    } else {
                        printf(" ");
                    }
                } else {
                    printf(" ");
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int test (void) {
    const int rows = 6;
    const int columns = 7;
    // char array[rows][columns];
    char** array = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        array[i] = (char*)malloc(columns * sizeof(char));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            array[i][j] = 'x';
            printf("%c", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    int diagonalCounterUp, diagonalCounterDown, verticalCounter, horizontalCounter = 1;

    // check in rounds starting from innermost circle around latest symbol, check-sizes increase by 2: 2, 4, 6
    for (int r = 2; r<=6; r = r+2) {
        findOpponentInsideOut(array, r);
        printf("Round done\n");
    }

    return 0;
}
