#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "enemies.h" // Include the enemies.h header

// Define characters for enemies
#define ENEMY 'X'

// Define enemy position and movement variables
int enemyX;
int enemyY;

// Function to initialize the enemy's position
void initializeEnemy() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize enemy position randomly within the maze
    do {
        enemyX = rand() % MAZE_HEIGHT;
        enemyY = rand() % MAZE_WIDTH;
    } while (maze[enemyX][enemyY] != EMPTY);
}

// Function to move the enemy randomly
void moveEnemy() {
    int direction = rand() % 4; // Randomly select a direction (0: Up, 1: Left, 2: Down, 3: Right)
    int newX = enemyX;
    int newY = enemyY;

    // Calculate the new position based on the selected direction
    if (direction == 0 && enemyX > 0 && maze[enemyX - 1][enemyY] == EMPTY) {
        newX--;
    } else if (direction == 1 && enemyY > 0 && maze[enemyX][enemyY - 1] == EMPTY) {
        newY--;
    } else if (direction == 2 && enemyX < MAZE_HEIGHT - 1 && maze[enemyX + 1][enemyY] == EMPTY) {
        newX++;
    } else if (direction == 3 && enemyY < MAZE_WIDTH - 1 && maze[enemyX][enemyY + 1] == EMPTY) {
        newY++;
    }

    // Update the enemy's position if it's a valid move
    if (maze[newX][newY] == EMPTY) {
        maze[enemyX][enemyY] = EMPTY; // Clear the old position
        enemyX = newX;
        enemyY = newY;
        maze[enemyX][enemyY] = ENEMY; // Update the new position
    }
}

// Function to check if the player has been caught by the enemy
int checkPlayerCaught() {
    return (playerX == enemyX && playerY == enemyY);
}

