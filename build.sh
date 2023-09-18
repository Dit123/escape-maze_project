#!/bin/bash

# Compile your C/C++ files one by one
gcc -o main main.c
gcc -o game_story game_story.c
# Add more compilation commands as needed

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful."
else
    echo "Compilation failed."
fi

