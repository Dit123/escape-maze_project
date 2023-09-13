#include <SDL2/SDL.h>
#include <stdio.h>
#include "main.h"
// Define constants for window dimensions
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Function to initialize SDL2 and create a window
SDL_Window* initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_Window* window = SDL_CreateWindow("Escape Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window creation failed: %s\n", SDL_GetError());
        return NULL;
    }

    return window;
}
// Function to handle game events
void handleEvents(SDL_Window* window, bool* quit) {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            *quit = true;
        }
         bool quit = false;
    SDL_Event event;

    while (!quit) {
        // Event handling loop
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_KEYDOWN) {
                // Handle key presses
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
			break;
                    case SDLK_DOWN:
                        // Handle the "Down" arrow key press
                        break;
                    case SDLK_LEFT:
                        // Handle the "Left" arrow key press
                        break;
                    case SDLK_RIGHT:
                        // Handle the "Right" arrow key press
                        break;
                    default:
                        // Handle other key presses if needed
                        break;
                }
	    }
	}
    }
	// Variables to store player position
int playerX = SCREEN_WIDTH / 2 - 25;
int playerY = SCREEN_HEIGHT / 2 - 25;

// Variables to store target position
int targetX = SCREEN_WIDTH - 100;
int targetY = SCREEN_HEIGHT - 100;

void updateGame() {
    // Check for player input (arrow key presses)
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (currentKeyStates[SDL_SCANCODE_UP]) {
        playerY -= 5;
    }
    if (currentKeyStates[SDL_SCANCODE_DOWN]) {
        playerY += 5;
    }
    if (currentKeyStates[SDL_SCANCODE_LEFT]) {
        playerX -= 5;
    }
    if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
        playerX += 5;
    }

    // Check if the player has reached the target
    if (playerX >= targetX && playerX <= targetX + 50 && playerY >= targetY && playerY <= targetY + 50) {
        // The player has reached the target, display a message
        printf("Congratulations! You reached the target.\n");

    }
}
void renderGame(SDL_Renderer* renderer) {
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Render the player character (a red rectangle)
    SDL_Rect playerRect = { playerX, playerY, 50, 50 };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    SDL_RenderFillRect(renderer, &playerRect);

    // Render the target area (a green rectangle)
    SDL_Rect targetRect = { targetX, targetY, 50, 50 };
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green color
    SDL_RenderFillRect(renderer, &targetRect);

    // Present the renderer (update the screen)
    SDL_RenderPresent(renderer);

    int main(int argc, char* argv[]) {
    // Initialize SDL2 and create a window
    SDL_Window* window = initSDL();
    if (!window) {
        return 1;
    }

    // Create a renderer for drawing graphics
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool quit = false;
    while (!quit) {
        // Handle game events
        handleEvents(window, &quit);

        // Update game logic
        updateGame();

        // Render graphics
        renderGame(renderer);
    }

    // Cleanup and quit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return (0);
    }
}

