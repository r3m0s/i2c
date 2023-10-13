//
// Created by remo on 13.10.2023.
//

#include <stdio.h>

int main (void) {
    int diagonalCounterUp, diagonalCounterDown, verticalCounter, horizontalCounter = 1;

    // check in rounds starting from innermost circle around latest symbol, check-sizes increase by 2: 2, 4, 6
    for (int r = 2; r<=6; r = r+2) {
        // iterate over rows
        for (int y = 0; y <= r; y++) {
            // iterate over columns
            for (int x = 0; x <= r; x++) {
                // increase counters until 4 are reached in any direction, then break
                if (y % r == 0 || x % r == 0) {
                    printf("x");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}