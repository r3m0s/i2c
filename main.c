//
// Created by remo on 18.09.2023.
//

#include "main.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void drawIntro();
void drawBoard(char *a);
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

  return 0;
}

void drawIntro() {
  printf("__   __ _                   ___                _              _   "
         "\n\\ \\ / /(_) ___  _ _        / __| ___  _ __ __ (_) _ _   _ _  | "
         "|_ \n \\   / | |/ -_)| '_|      | (_ |/ -_) \\ V  V /| || ' \\ | ' "
         "\\ |  _|\n  \\_/  |_|\\___||_|         \\___|\\___|  \\_/\\_/ "
         "|_||_||_||_||_| \\__|\n\n");
}

void drawBoard(char *a) {
  for (int i = 5; i >= 0; i--) {
    printf("  ______________________________________________________\n"
           " /\t\\/\t\\/\t\\/\t\\/\t\\/\t\\/\t\\\n"
           "||   %c  ||   %c  ||   %c  ||   %c  ||   %c  ||   %c  ||   %c  ||\n"
           " \\\t/\\\t/\\\t/\\\t/\\\t/\\\t/\\\t/\n",
           a[0 + (i * 7)], a[1 + i * 7], a[2 + i * 7], a[3 + i * 7],
           a[4 + i * 7], a[5 + i * 7], a[6 + i * 7]);
  }

  printf("  ___1_______2_______3_______4_______5_______6_______7__\n");
}

char *getEmptyGame() {
  char *array = (char *)malloc(42 * sizeof(char));

  for (int i = 0; i < 42; i++) {
    array[i] = ' ';
  }

  return array;
}
