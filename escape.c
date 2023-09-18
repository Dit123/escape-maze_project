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
#include "enemies.h"

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

    int x = 0;
    int y = 0;
    maze[x][y] = EMPTY;

    while (1) {
        int direction = rand() % 4; // Randomly select a direction (0: Up, 1: Left, 2: Down, 3: Right)

        // Move in the selected direction (if valid)
        if (direction == 0 && x > 0 && maze[x - 1][y] == WALL) {
            maze[--x][y] = EMPTY;
        } else if (direction == 1 && y > 0 && maze[x][y - 1] == WALL) {
            maze[x][--y] = EMPTY;
        } else if (direction == 2 && x < MAZE_HEIGHT - 1 && maze[x + 1][y] == WALL) {
            maze[++x][y] = EMPTY;
        } else if (direction == 3 && y < MAZE_WIDTH - 1 && maze[x][y + 1] == WALL) {
            maze[x][++y] = EMPTY;
        } else {
		int found = 0;
            for (int i = 0; i < MAZE_HEIGHT; i++) {
                for (int j = 0; j < MAZE_WIDTH; j++) {
                    if (maze[i][j] == EMPTY) {
                        x = i;
                        y = j;
                        found = 1;
                        break;
                    }
                }
                if (found) break;
            }
        }

	if (x == MAZE_HEIGHT - 1 && y == MAZE_WIDTH - 1) {
            // Reached the exit
            maze[x][y] = EXIT;
            break;
        }
    }
}

// Function to print the maze
void printMaze(const char map[MAZE_HEIGHT][MAZE_WIDTH]) {
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            printw("%c ", map[i][j]); // Use printw instead of printf for ncurses
        }
        printw("\n");
    }
    refresh(); // Refresh the screen after printing
}

void movePlayer(char direction, int selectedLevel) {
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
        // Player reached the exit, increase the score and generate a new maze
        score += 10;
        generateMaze(selectedLevel); // Generate a new maze with the selected level
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
    int selectedLevel = rand() % NUM_LEVELS + 1;
    generateMaze(selectedLevel);
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
    while (1) {
        input = getch();

        if (input == 'W' || input == 'A' || input == 'S' || input == 'D') {
            movePlayer(input, selectedLevel);
            printMaze(maze);
        }
    }

    // End ncurses (for Linux)
    endwin();

    return 0;
}

