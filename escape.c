/** 
 * @file escape.c
 * @author cheluh itulua (debhaitulua@gmail.com)
 *
 * escape - function that controls all player activities within the escape maze
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ncurses.h>
#include "escape_maps.h"

// Define the size of the maze
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Define characters for maze elements
#define WALL '#'
#define PLAYER 'P'
#define EXIT 'E'
#define EMPTY ' '

// Define player position
int playerX = 0;
int playerY = 0;

// Define maze variables
char maze[MAZE_HEIGHT][MAZE_WIDTH];

// Define game variables
int score = 0;
int selectedLevel = 1;

#define NUM_LEVELS 3

extern const char mazeMap1[MAZE_HEIGHT][MAZE_WIDTH];
extern const char mazeMap2[MAZE_HEIGHT][MAZE_WIDTH];
extern const char mazeMap3[MAZE_HEIGHT][MAZE_WIDTH];
extern const char mazeMap4[MAZE_HEIGHT][MAZE_WIDTH];
extern const char mazeMap5[MAZE_HEIGHT][MAZE_WIDTH];
extern const char mazeMap6[MAZE_HEIGHT][MAZE_WIDTH];
extern const char mazeMap7[MAZE_HEIGHT][MAZE_WIDTH];
extern const char mazeMap8[MAZE_HEIGHT][MAZE_WIDTH];
extern const char mazeMap9[MAZE_HEIGHT][MAZE_WIDTH];

// Function to generate a random maze
void generateMaze(int level) {
    // Initialize the maze with walls
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            maze[i][j] = WALL;
        }
    }

    // Choose the maze map based on the level
    const char* selectedMazeMap;
    switch (level) {
        case 1:
            selectedMazeMap = mazeMap1;
            break;
        case 2:
            selectedMazeMap = mazeMap2;
            break;
        // Add more cases for additional levels
        default:
            selectedMazeMap = mazeMap1; // Default to level 1
            break;
    }

    / Copy the selected maze map into the maze array
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            maze[i][j] = selectedMazeMap[i][j];
        }
    }
}

// Modify the printMaze function like this in both files
void printMaze(const char map[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(char direction) {
    int newX = playerX;
    int newY = playerY;

    if (direction == 'W' && playerX > 0 && maze[playerX - 1][playerY] != WALL) {
        newX--;
    } else if (direction == 'A' && playerY > 0 && maze[playerX][playerY - 1] != WALL) {
        newY--;
    } else if (direction == 'S' && playerX < MAZE_HEIGHT - 1 && maze[playerX + 1][playerY] != WALL) {
        newX++;
    } else if (direction == 'D' && playerY < MAZE_WIDTH - 1 && maze[playerX][playerY + 1] != WALL) {
        newY++;
    }

    if (maze[newX][newY] == EXIT) {
        // Player reached the exit, increase the score and move to the next level
        score += 10;
        selectedLevel++;
        generateMaze();
    } else if (maze[newX][newY] != WALL) {
        // Valid move, update player position
        playerX = newX;
        playerY = newY;
        score--;
    }
}

void printMazeSize() {
    printf("Maze Size: %dx%d\n", MAZE_WIDTH, MAZE_HEIGHT);
}

int main() {
	// Define the maze map as a 2D character array (10x10)
char map[10][10] = {
    {'S', ' ', '#', '#', ' ', '#', ' ', ' ', ' ', 'E'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', ' '},
    {'#', ' ', '#', '#', ' ', ' ', ' ', ' ', ' ', ' '},
    {'#', ' ', ' ', ' ', ' ', '#', '#', ' ', ' ', ' '},
    {'#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' '},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', ' '},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', ' '},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' '},
    {'#', '#', '#', '#', '#', ' ', '#', '#', '#', ' '},
};

    // Seed the random number generator
    srand(time(NULL));

    // Initialize ncurses (for Linux)
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    // Generate the initial maze and print it
    generateMaze();
    printMaze(maze);
    printMazeSize();


        memcpy(maze, mazeMap1, sizeof(maze));
        memcpy(maze, mazeMap2, sizeof(maze));
        memcpy(maze, mazeMap3, sizeof(maze));
        memcpy(maze, mazeMap4, sizeof(maze));
        memcpy(maze, mazeMap5, sizeof(maze));
        memcpy(maze, mazeMap6, sizeof(maze));
        memcpy(maze, mazeMap7, sizeof(maze));
        memcpy(maze, mazeMap8, sizeof(maze));
        memcpy(maze, mazeMap9, sizeof(maze));


    char input;
    int level;
    while (1) {
	    level = (rand() % NUM_LEVELS) + 1;
	    generateMaze(selectedLevel);
        input = getch();

        if (input == 'W' || input == 'A' || input == 'S' || input == 'D') {
            movePlayer(input);
            printMaze(maze);
        }
    }

    // End ncurses (for Linux)
    endwin();

    return 0;
}

