/** 
 * @file escape.c
 * @author cheluh itulua (debhaitulua@gmail.com)
 *
 * escape - function that controls all player activities within the escape maze
 */

#include <stdio.h>
#include "main.h"

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

    // Initialize player position
    int playerX = 0;
    int playerY = 0;

    // Initialize game mode (0: Playing, 1: Win, 2: Lose)
    int mode = 0;

    while (mode == 0) {
        // Print the maze
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }

        // Check if the player has reached the exit
        if (playerX == 9 && playerY == 9) {
            mode = 1; // Player wins
            break;
        }

        // Prompt for direction
        char direction;
        printf("Enter a direction (W/A/S/D): ");
        scanf(" %c", &direction);

        // Update player position based on direction
        if (direction == 'W' && playerX > 0 && map[playerX - 1][playerY] != '#') {
            playerX--;
        } else if (direction == 'A' && playerY > 0 && map[playerX][playerY - 1] != '#') {
            playerY--;
        } else if (direction == 'S' && playerX < 9 && map[playerX + 1][playerY] != '#') {
            playerX++;
        } else if (direction == 'D' && playerY < 9 && map[playerX][playerY + 1] != '#') {
            playerY++;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }

    // Game result
    if (mode == 1) {
        printf("Congratulations! You escaped the maze!\n");
    } else {
        printf("Sorry, you lost the game.\n");
    }

    return 0;
}
