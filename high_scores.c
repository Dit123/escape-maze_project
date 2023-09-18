// high_scores.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "high_scores.h"

// Define the maximum number of high scores to store
#define MAX_HIGH_SCORES 10

// Structure to represent a high score entry
struct HighScoreEntry {
    char name[MAX_NAME_LENGTH];
    int score;
};

// Array to store high scores
struct HighScoreEntry highScores[MAX_HIGH_SCORES];

// Function to initialize the high scores
void initializeHighScores() {
    for (int i = 0; i < MAX_HIGH_SCORES; i++) {
        strcpy(highScores[i].name, "Unknown");
        highScores[i].score = 0;
    }
}

// Function to load high scores from a file
void loadHighScores() {
    FILE* file = fopen("high_scores.txt", "r");
    if (file != NULL) {
        for (int i = 0; i < MAX_HIGH_SCORES; i++) {
            if (fscanf(file, "%s %d", highScores[i].name, &highScores[i].score) != 2) {
                break; // Stop if unable to read more entries
            }
        }
        fclose(file);
    }
}

// Function to save high scores to a file
void saveHighScores() {
    FILE* file = fopen("high_scores.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < MAX_HIGH_SCORES; i++) {
            fprintf(file, "%s %d\n", highScores[i].name, highScores[i].score);
        }
        fclose(file);
    }
}

// Function to add a new high score entry
void addHighScore(const char* playerName, int playerScore) {
    for (int i = 0; i < MAX_HIGH_SCORES; i++) {
        if (playerScore > highScores[i].score) {
            // Shift lower scores down to make room for the new high score
            for (int j = MAX_HIGH_SCORES - 1; j > i; j--) {
                strcpy(highScores[j].name, highScores[j - 1].name);
                highScores[j].score = highScores[j - 1].score;
            }
            // Add the new high score
            strncpy(highScores[i].name, playerName, MAX_NAME_LENGTH - 1);
            highScores[i].score = playerScore;
            break;
        }
    }
}

// Function to display the high scores
void displayHighScores() {
    printf("High Scores:\n");
    for (int i = 0; i < MAX_HIGH_SCORES; i++) {
        printf("%d. %s - %d\n", i + 1, highScores[i].name, highScores[i].score);
    }
}


