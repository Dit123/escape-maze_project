#include <SDL2/SDL.h>

void runGame() {
	quit = false;
	SDL_Event event;
	
	
	while (true) {
        // Event handling and game logic...
	 while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
	    } else if (event.type == SDL_KEYDOWN) {
		    switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        // Handle the "Up" arrow key press
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



        if (playerWins || playerLoses || userQuits) {
		 playerX += playerSpeedX; // Update player's horizontal position
playerY += playerSpeedY; // Update player's vertical position

            return; // Exit the function and the game
        }


int main(int argc, char* argv[]) {
    // Set display driver hint (if needed)
    // This should be placed before SDL_Init
    SDL_SetHint(SDL_HINT_VIDEO_DRIVER, "x11"); // Set the display driver (e.g., x11)

    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

// Create a window and a renderer
    SDL_Window* window = SDL_CreateWindow("Escape Maze", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    runGame();

// Check for collisions
if (checkCollision(playerX, playerY, enemyX, enemyY)) {
    playerHealth -= 10; // Reduce player health on collision with an enemy
}

// Handle user input (e.g., move the player based on keyboard input)
if (isKeyPressed(SDLK_LEFT)) {
    playerSpeedX = -5;
} else if (isKeyPressed(SDLK_RIGHT)) {
    playerSpeedX = 5;
} else {
    playerSpeedX = 0;
}
// Update game variables
score += 1; 
// Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

	// Draw object hear
	 SDL_Rect playerRect = { playerX, playerY, playerWidth, playerHeight };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    SDL_RenderFillRect(renderer, &playerRect);

    SDL_Rect enemyRect = { enemyX, enemyY, enemyWidth, enemyHeight };
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue color
    SDL_RenderFillRect(renderer, &enemyRect);
    // Present the renderer
        SDL_RenderPresent(renderer);
    }
    // Clean up and quit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
