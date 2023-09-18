#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ncurses.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include "escape_maps.h"
#include "enemies.h"
#include "high_scores.h"
#include "sound_effects.h"

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
    // Initialize SDL and Mixer for sound effects
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return 1;
    }
    
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return 1;
    }

    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
    srand(time(NULL));

    // Load sound effects
    if (!loadSoundEffects()) {
        printf("Failed to load sound effects!\n");
        return 1;
    }

    int selectedLevel = 1;

    while (1) {
        clear();
        printw("Level: %d\n", selectedLevel);
        printMazeSize();
        generateMaze(selectedLevel);
        printMaze(maze);
        playerX = 0;
        playerY = 0;
        score = 0;

        while (1) {
            char move = getch();

            if (move == 'Q' || move == 'q') {
                // Quit the game
                endwin();
                Mix_CloseAudio();
                SDL_Quit();
                return 0;
            } else if (move == 'N' || move == 'n') {
                // Move to the next level
                selectedLevel = (selectedLevel % NUM_LEVELS) + 1;
                break;
            }

            movePlayer(move, selectedLevel);

            if (score < 0) {
                // Player lost the game
                printw("Game Over! Press 'N' for the next level or 'Q' to quit.\n");
                break;
            }

            clear();
            printw("Level: %d\n", selectedLevel);
            printMazeSize();
            printMaze(maze);
            printw("Score: %d\n", score);
            refresh();
        }
    }

    // Clean up SDL and ncurses
    endwin();
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}

