//
// Created by remo on 18.09.2023.
//

#include "draw.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char *getEmptyGame();

int main() {
  int favoriteNumber = 0;

  // printf("Please enter your favorite number\n");
  // scanf("%d", &favoriteNumber);
  // printf("You entered number: %d\n", favoriteNumber);

  char *game = getEmptyGame();

  game[1] = 'x';
  game[5] = 'o';
  game[7] = 'x';

  drawIntro();
  drawBoard(game);

  drawWinP1();
  drawWinP2();

  return 0;
}


char *getEmptyGame() {
  char *array = (char *)malloc(42 * sizeof(char));

  for (int i = 0; i < 42; i++) {
    array[i] = ' ';
  }

  return array;
}
