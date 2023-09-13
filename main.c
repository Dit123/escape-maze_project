/**
 * @file - main.c
 * @author cheluh itulua (debhaitulua@gmail.com)
 *
 *  main - Driver function for the entire program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "main.h"

// Function to play a selected maze program
void playMaze(char *programName);

int main() {
    char choice;

    printf("Welcome to the Maze Escape Game!\n");

    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Play Maze 1 (Easy)\n");
        printf("2. Play Maze 2 (Medium)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("You selected Maze 1 (Easy).\n");
                playMaze("escape");
                break;
            case '2':
                printf("You selected Maze 2 (Medium).\n");
                playMaze("escape-maps");
                break;
            case '3':
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

void playMaze(char *programName) {
    char compileCommand[50];
    char runCommand[50];

    // Compile the selected maze program
    sprintf(compileCommand, "gcc -o %s %s.c -lSDL2", programName, programName);
    int compileResult = system(compileCommand);

    if (compileResult != 0) {
        printf("Compilation failed. Make sure SDL2 is installed.\n");
        return;
    }

    // Run the selected maze program
    sprintf(runCommand, "./%s", programName);
    system(runCommand);
}

