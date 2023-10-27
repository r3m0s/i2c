//
// Created by remo on 18.09.2023.
//

#include "draw.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "checker.c"

char *getEmptyGame();
void getComment(int *);
int getInput();
int fillBoard(int *, char *, char);

int main() {

  // allocate memory for the player count
  int *player = (int *)calloc(1, sizeof(int));
  *player = 0;

  // allocate memory for the game board
  char *game = getEmptyGame();

  //allocate memory for the player input
  int *input = (int *)calloc(1, sizeof(int));

  //lgame[1] = 'x';
  // game[5] = 'o';
  // game[7] = 'x';

  drawIntro();
  drawRules();
  drawBoard(game);

  while (1) {
    *input = -1;

    printf("\n\nIt's your turn player %d\n", *player % 2 ? 2 : 1);
    printf("Where do you want to put your chip? ");

    *input = getInput();

    getComment(input);

    if (*input > 7 || *input < 0) {
      continue;
    }

    if (*input == 0){
      *player = -1;
      break;
    }

    if(fillBoard(input, game, *player % 2 ? 'o' : 'x') < 0) continue;

    drawBoard(game);
    printf("%d", *input);
    checkState(game);
    *player += 1;
  }


  if(*player > 0){
    *player % 2 ? drawWinP2() : drawWinP1();
  } else {
    printf("Hope you didn't ragequit!\n");
  }
  
  free(input);
  free(game);
  free(player);
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

  printf("The value needs to be between 1 and 9!\n");
}

// gets the user Input and converts it into a number
int getInput() {
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

int fillBoard(int *column, char *board, char chip){
  for(int i = 0; i < 6; i++){
    if(board[(*column + (i * 7)) - 1] == ' '){
      board[(*column + (i * 7)) - 1] = chip;
      return 0;
    }
  }
printf("This column is already full!\n");
return -1;
}
