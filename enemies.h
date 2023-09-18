#ifndef ENEMIES_H
#define ENEMIES_H
// Define the maze size (assuming it's the same as in escape.c)
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Declare functions and variables related to enemies
extern int enemyX;
extern int enemyY;

void initializeEnemy();
void moveEnemy();
int checkPlayerCaught();

#endif
