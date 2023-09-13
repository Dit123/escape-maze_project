#ifndef MAIN_H
#define MAIN_H


// Function prototypes for functions used in escape.c
void initializeGame(int* playerX, int* playerY, int* mode);
void printMaze(const char map[10][10]);
int isGameComplete(int playerX, int playerY, int mode);
void playEscapeGame(char map[10][10], int* playerX, int* playerY, int* mode);

// Function prototypes for functions used in the code
void startGame();
void showInstructions();
void displayGameInfo();
void exitGame();

#endif // MAIN_H
