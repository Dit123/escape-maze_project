#include <stdio.h>
#include <string.h>
#include "main.h"

int main() {
    printf("Welcome to 'Escape the Maze'!\n");
    printf("\n");

    int choice;

    while (1) {
        printf("Main Menu:\n");
        printf("1. Start Game\n");
        printf("2. Game Instructions\n");
        printf("3. About the Game\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        // Read user's choice
        scanf("%d", &choice);

        if (choice == 1) {
            // Start the game
            printf("Starting the game...\n");
            // Place your game initialization and main game loop here
            break;
        } else if (choice == 2) {
            // Game instructions
            printf("\nGame Instructions:\n");
            printf("Navigate through the maze to reach the exit point.\n");
            printf("Use arrow keys to move your character.\n");
            printf("Avoid obstacles and find the hidden path to escape!\n");
            printf("\n");
        } else if (choice == 3) {
            // About the game
            printf("\nAbout the Game:\n");
            printf("'Escape the Maze' is an exciting adventure game where you must navigate through a complex maze to reach safety.\n");
            printf("Enjoy hours of fun as you solve puzzles and overcome obstacles.\n");
            printf("\n");
        } else if (choice == 4) {
            // Exit the game
            printf("Exiting the game. Goodbye!\n");
            break;
        } else {
            // Invalid choice
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

