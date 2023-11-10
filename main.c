//
// Created by remo on 18.09.2023.
//

#include "checker.h"
#include "draw.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char *getEmptyGame();

void getComment(int *);

int getInteger();

char getChar();

int fillBoard(int *, char *, char);

int main() {

  int g = 1;
  do {
    // allocate memory for the player count
    int *player = (int *)calloc(1, sizeof(int));
    *player = 0;

    // allocate memory for the game board
    char *game = getEmptyGame();

    // allocate memory for the player input
    int *input = (int *)calloc(1, sizeof(int));

    drawIntro();
    drawRules();
    drawBoard(game);

    // initialize game loop
    int p = 0;

    do {
      *input = -1;

      printf("\n\nIt's your turn player %d\n", *player % 2 ? 2 : 1);
      printf("Where do you want to put your chip? ");

      *input = getInteger();

      getComment(input);

      // start at the top of the loop if the column is not in the allowed range
      if (*input > 7 || *input < 0) {
        continue;
      }

      // quit the game if the input was 0
      if (*input == 0) {
        *player = -1;
        break;
      }

      // fill the game with the approprate char
      if (fillBoard(input, game, *player % 2 ? 'o' : 'x') < 0)
        continue;

      // draw the board with the actual state
      drawBoard(game);

      // check if a player won
      // if one won then exit the game loop
      if(*player > 6)
        p = checkState(input, game);

      // increment the player count
      *player += 1;
    } while (p == 0);

    // check which one of the players won and draw the winner screen
    if (*player > 0) {
      (*player - 1) % 2 ? drawWinP2() : drawWinP1();
    }

    // go into the new game loop
    // ask if the players want to go again or quit the whole game
    int n = 1;
    do {
      printf("Wanna play again? (y/n): ");
      char input;
      input = getChar();
      if (input == 'y') {
        g = 1;
        n = 0;
      } else if (input == 'n') {
        g = 0;
        n = 0;
      } else {
        printf("Tippe y oder n \n");
        n = 1;
      }
    } while (n);

    // free the allocated variables
    free(input);
    free(game);
    free(player);
  } while (g);

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

// Displays the correct message for the entered input of the user
void getComment(int *column) {

  if (*column < 0) {
    printf("Fault while reading the Input!\n");
    return;
  }

  if (*column == 0) {
    printf("Thanks for playing! Goodbye\n");
    return;
  }

  if (*column > 0 && *column < 8) {
    return;
  }

  printf("The value needs to be between 1 and 7!\n");
}

// gets the user Input and converts it into a number
int getInteger() {
  char temp[10];
  char *endptr;
  int number;

  fgets(temp, 10, stdin);

  number = strtol(temp, &endptr, 10);

  if (*endptr != '\n') {
    return -1;
  }

  return number;
}

char getChar() {
  char temp[2];
  char input;

  fgets(temp, 10, stdin);

  input = temp[0];

  return input;
}

int fillBoard(int *column, char *board, char chip) {
  for (int i = 0; i < 6; i++) {
    if (board[(*column + (i * 7)) - 1] == ' ') {
      board[(*column + (i * 7)) - 1] = chip;
      return 0;
    }
  }
  printf("This column is already full!\n");
  return -1;
}
