# Escape - Maze Game

## Introduction
Escape is an exciting maze game that challenges players to find their way out of intricate mazes filled with twists, turns, and obstacles. Put your problem-solving skills to the test and see if you can escape from each level.

## Features
- **Multiple Levels:** Enjoy a variety of challenging mazes with increasing complexity.
- **Interactive Gameplay:** Navigate through the maze using intuitive controls.
- **Obstacles:** Encounter obstacles and puzzles that require clever solutions to proceed.
- **Time Challenge:** Race against the clock to escape each level as quickly as possible.
- **Scoring:** Keep track of your best times and aim for the top of the leaderboard.
- **Graphics and Sound:** Immersive graphics and sound effects enhance the gaming experience.

## Getting Started
To start playing Escape, follow these simple steps:

1. **Installation:** Clone this repository to your local machine.

    ```
    git clone https://github.com/Dit123/escape-maze.git
    ```

2. **Dependencies:** Ensure you have all the required dependencies installed. 

3. **Running the Game:** Compile and Execute the main game script to launch Escape.

    ```
    gcc escape.c -o escape -lSDL2 -lSDL2_image -lSDL2_ttf
    ./escape
    ```

4. **Controls:** Use the arrow keys (or your preferred control scheme) to navigate through the maze.

## Raycasting and Wall Rendering
Escape uses raycasting to create a 3D-like view of the maze. It simulates the projection of 2D walls onto the player's view, providing a realistic and immersive experience. Raycasting is a technique often used in classic first-person shooter games.

## Gameplay
- Your objective is to find the exit of each maze within the shortest time possible.
- Be cautious of obstacles and dead ends. Plan your path carefully.
- Your progress and best times are recorded, so you can always strive to beat your own records.

## Contributing
We welcome contributions from the community! If you'd like to contribute to the project, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and ensure they are well-documented.
4. Test your changes thoroughly.
5. Create a pull request, explaining your changes and their purpose.

## Acknowledgments
We would like to thank all contributors to this project, as well as the creators of the tools and libraries used.

## Contact
If you have any questions or feedback, please feel free to contact us at debhaitulua@gmail.com

Happy escaping!
