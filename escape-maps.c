/**
 * @file maps.c
 * @author cheluh itulua (debhaitulua@gmail.com)
 *
 * maze- shows the size of the maze
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS];
bool visited[ROWS][COLS];


// Define directions for navigating the maze
const int dx[] = {0, 1, 0, -1}; // Right, Down, Left, Up
const int dy[] = {1, 0, -1, 0};

// Function to check if a cell is within the maze boundaries
bool is_valid(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS;
}

// Function to initialize the maze with walls
void initialize_maze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = '#';
        }
    }
}

// Function to print the current state of the maze
void print_maze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Depth-First Search algorithm to create the maze
void generate_maze(int x, int y) {
    visited[x][y] = true;
    maze[x][y] = ' ';
    
    // Randomly shuffle the directions
    int directions[4] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }

    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[directions[i]];
        int new_y = y + dy[directions[i]];

        if (is_valid(new_x, new_y) && !visited[new_x][new_y]) {
            maze[x + dx[directions[i] / 2]][y + dy[directions[i] / 2]] = ' ';
            generate_maze(new_x, new_y);
        }
    }
}

int path[ROWS][COLS] = {
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 1, 0},
    {0, 1, 1, 1, 1, 1, 0, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
struct Point {
    int x, y;
    bool isValid(int x, int y){
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == 0);
}

// Breadth-First Search to find a path through the maze
bool findPath(int startX, int startY, int endX, int endY) {
    // Create a queue for BFS
    std::queue<Point> q;
    Point start = {startX, startY};
    q.push(start);

    // Create a 2D array to track visited cells
    bool visited[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            visited[i][j] = false;
        }
    }

    visited[startX][startY] = true;

    // Arrays to represent possible movements: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        int x = current.x;
        int y = current.y;

        // Check if we reached the end point
        if (x == endX && y == endY) {
            return true; // Path found
        }

        // Explore neighboring cells
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY) && !visited[newX][newY]) {
                Point next = {newX, newY};
                q.push(next);
                visited[newX][newY] = true;
            }
        }
    }

    return false; // No path found
}
int main() {
    srand(time(NULL));
    initialize_maze();
    generate_maze(0, 0); // Start generating the maze from the top-left corner
    maze[ROWS - 1][COLS - 1] = 'E'; // Mark the exit
    printf("Generated Maze:\n");
    print_maze();
    int startX = 0, startY = 0;
    int endX = 4, endY = 4;

    if (findPath(startX, startY, endX, endY)) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }


    return 0;
}

