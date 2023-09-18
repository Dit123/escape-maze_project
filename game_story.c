/**
 * @file game_story.c
 * @author cheluh itulua (debhaitulua@gmail.com)
 *
 * game_story -  This file is used for more detailed storytelling or narrative elements in your game
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    int decision;
    printf("You stand at a crossroads. Choose your path:\n");
    printf("1 - Take the left path\n");
    printf("2 - Take the right path\n");
    printf("Enter your choice: ");
    scanf("%d", &decision);

    // Branching story based on player's choice
    if (decision == 1) {
        printf("You chose the left path. You find a key that might be useful later.\n");
    } else if (decision == 2) {
        printf("You chose the right path. You stumble upon a locked door.\n");
        printf("You'll need to find a key to proceed.\n");
    } else {
        printf("Invalid choice. You hesitate at the crossroads.\n");
    }

    // Continue the story based on the player's progress
    int choice;
    int progress = 0;
    printf("You stand at a crossroads. Choose your path:\n");
    printf("1 - Take the left path\n");
    printf("2 - Take the right path\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
    // Story continuation for choice 1
    progress = 1; // Update the progress variable
} else if (choice == 2) {
    // Story continuation for choice 2
    progress = 2; // Update the progress variable
} else {
    // Handle invalid choices or other scenarios
    printf("invalid choice.\n");
}



    // At the end of the story, check if the player successfully escaped
    int escaped = 1; // Set to 1 if the player escaped, 0 otherwise

    if (escaped) {
        printf("\nCongratulations, %s! You successfully navigated the maze and escaped!\n", playerName);
    } else {
        printf("\nSorry, %s, your adventure ends here. Better luck next time!\n", playerName);
    }

    return 0;
}

