#include <SDL.h>
#include <stdio.h>
#include "sound_effects.h" // Include your own header file for sound effects

// Declare sound effect variables
static Mix_Chunk* soundEffect = NULL;

// Initialize the sound effects module
int initSoundEffects() {
    // Initialize SDL Audio subsystem
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        fprintf(stderr, "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return 0;
    }

    return 1;
}

// Load sound effect from file
int loadSoundEffect(const char* filename) {
    soundEffect = Mix_LoadWAV(filename);
    if (!soundEffect) {
        fprintf(stderr, "Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        return 0;
    }

    return 1;
}

// Play the loaded sound effect
void playSoundEffect() {
    Mix_PlayChannel(-1, soundEffect, 0);
}

// Cleanup and close the sound effects module
void closeSoundEffects() {
    if (soundEffect) {
        Mix_FreeChunk(soundEffect);
        soundEffect = NULL;
    }

    Mix_Quit();
    SDL_Quit();
}

