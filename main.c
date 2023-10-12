//
// Created by remo on 18.09.2023.
//

#include "draw.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char *getEmptyGame();
int getAndCheckInput(int *);

int main() {

  // allocate memory for the player count
  int *player = (int *)calloc(1, sizeof(int));
  *player = 0;

  // allocate memory for the game board
  char *game = getEmptyGame();

  // game[1] = 'x';
  // game[5] = 'o';
  // game[7] = 'x';

  drawIntro();
  drawRules();
  drawBoard(game);

  while (1) {
    int input = -1;
    printf("\n\nIt's your turn player %d\n", *player % 2 ? 2 : 1);
    printf("Where do you want to put your chip? ");

    if (getAndCheckInput(&input) <= 0) {
      break;
    } else if (getAndCheckInput(&input) != 1) {
      continue;
    }

  }

  drawWinP1();
  drawWinP2();

  return EXIT_SUCCESS;
}

// allocates an array of chars, that represents the game board and returns the
// pointer
char *getEmptyGame() {
  char *array = (char *)calloc(42, sizeof(char));

  for (int i = 0; i < 42; i++) {
    array[i] = ' ';
  }

  return array;
}

int getAndCheckInput(int *column) {
  if (scanf("%d", column)) {
    if (*column < 0) {
      printf("Fault while reading the Input!");
      return -1;
    }

    if (*column == 0) {
      printf("Thanks for playing! Goodbye\n");
      return 0;
    }

    if (*column > 0 && *column < 10) {
      return 1;
    }

    printf("The value needs to be between 1 and 9!\n");
    return 99;
  } else {
    return -1;
  }
}
