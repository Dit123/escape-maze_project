/**
 * @file game_intro.c
 * @author cheluh itulua (debhaitulua@gmail.com)
 *
 * game_intro - This file can contain code that explains the game's objective, how to play, and any other relevant information for the player before they start the game.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the size of the maze
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Function to print the maze
void printMaze(const char maze[MAZE_HEIGHT][MAZE_WIDTH]) {
    system("clear"); // Clear the terminal (for Linux/Unix systems)
    printf("Escape Maze Game\n");

    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Introduction
    printf("Welcome to the Escape Maze Game!\n");
    printf("Please enter your name: ");

    // Read player's name
    char playerName[50];
    fgets(playerName, sizeof(playerName), stdin);
    playerName[strcspn(playerName, "\n")] = '\0'; // Remove newline character

    // Display a personalized greeting
    printf("\nHello, %s! You find yourself trapped in a maze.\n", playerName);
    printf("Your mission is to escape the maze and reach the exit (E).\n");
    printf("You can move through the maze using the following commands:\n");
    printf("W - Move Up\n");
    printf("A - Move Left\n");
    printf("S - Move Down\n");
    printf("D - Move Right\n");
    printf("Try to find your way out while avoiding obstacles (#).\n");

    // Initialize the maze (replace with your maze data)
    char maze[MAZE_HEIGHT][MAZE_WIDTH] = {
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

    int playerX = 0;
    int playerY = 0;

    // Game loop
    while (maze[playerY][playerX] != 'E') {
        printMaze(maze);

        // Prompt for movement
        char move;
        printf("Enter your move (W/A/S/D): ");
        scanf(" %c", &move);

        // Update player position based on move
        switch (move) {
            case 'W':
                if (playerY > 0 && maze[playerY - 1][playerX] != '#') {
                    maze[playerY][playerX] = ' ';
                    playerY--;
                }
                break;
            case 'A':
                if (playerX > 0 && maze[playerY][playerX - 1] != '#') {
                    maze[playerY][playerX] = ' ';
                    playerX--;
                }
                break;
            case 'S':
                if (playerY < MAZE_HEIGHT - 1 && maze[playerY + 1][playerX] != '#') {
                    maze[playerY][playerX] = ' ';
                    playerY++;
                }
                break;
            case 'D':
                if (playerX < MAZE_WIDTH - 1 && maze[playerY][playerX + 1] != '#') {
                    maze[playerY][playerX] = ' ';
                    playerX++;
                }
                break;
            default:
                printf("Invalid move. Please try again.\n");
        }
    }

    printMaze(maze);

    printf("Congratulations, %s! You escaped the maze!\n", playerName);

    return 0;
}

