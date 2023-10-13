#include <stdio.h>

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

void drawWinP1() {
  printf(" ___  _ __  _       _                    _\n"
         "/ __|| '_ \\(_) ___ | | ___  _ _         / |\n"
         "\\__ \\| .__/| |/ -_)| |/ -_)| '_|        | |\n"
         "|___/|_|   |_|\\___||_|\\___||_|          |_|\n");
}

void drawWinP2() {
  printf(" ___  _ __  _       _                    ___\n"
         "/ __|| '_ \\(_) ___ | | ___  _ _         |_  )\n"
         "\\__ \\| .__/| |/ -_)| |/ -_)| '_|         / / \n"
         "|___/|_|   |_|\\___||_|\\___||_|          /___|\n");
}

void drawRules() {
  printf("The aim of the game is to get 4 chips of yourself in a row.\n");
  printf("The rows can be vertical, horizontal or diagonal.\n");
  printf("The players take turns putting chips into a column.\n\n");
  printf("When asked to place a chip just enter the number of the column you want to place the chip.\n");
  printf("To quit just enter '0'\n");
}

