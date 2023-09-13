// Maze game variables
const maze = document.getElementById('maze');
const cells = document.querySelectorAll('.cell');
const player = document.querySelector('.player');
const exit = document.querySelector('.exit');
const feedback = document.getElementById('feedback');
const result = document.getElementById('result');
const directionInput = document.getElementById('direction-input');

let playerX = 0;
let playerY = 0;
let gameMode = 'playing';

// Maze layout (0: empty, 1: wall, 2: exit)
const mazeLayout = [
    [0, 1, 0, 1, 0, 1, 0, 0, 0, 2],
    [1, 0, 0, 0, 0, 0, 0, 1, 1, 0],
    [1, 0, 1, 1, 0, 0, 0, 0, 0, 0],
    [1, 0, 0, 0, 0, 1, 1, 0, 0, 0],
    [1, 1, 1, 1, 0, 0, 0, 0, 0, 0],
    [1, 0, 0, 0, 0, 0, 0, 1, 1, 0],
    [1, 0, 1, 0, 0, 0, 0, 0, 0, 0],
    [1, 0, 1, 0, 1, 1, 0, 1, 0, 0],
    [1, 0, 0, 0, 0, 0, 0, 1, 0, 0],
    [1, 1, 1, 1, 1, 0, 1, 1, 1, 0],
];

// Function to update the player's position on the maze
function updatePlayerPosition() {
    cells[playerY * 10 + playerX].appendChild(player);
}

// Function to handle player movement
function movePlayer(direction) {
    if (gameMode === 'playing') {
        const newX = playerX + (direction === 'D' ? 1 : direction === 'A' ? -1 : 0);
        const newY = playerY + (direction === 'S' ? 1 : direction === 'W' ? -1 : 0);

        // Check for wall collision
        if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10 && mazeLayout[newY][newX] !== 1) {
            playerX = newX;
            playerY = newY;
            updatePlayerPosition();

            // Check for exit
            if (mazeLayout[newY][newX] === 2) {
                gameMode = 'win';
                result.textContent = 'Congratulations! You escaped the maze!';
            }
        } else {
            feedback.textContent = 'Invalid move! Try again.';
        }
    }
}

// Event listener for direction input
directionInput.addEventListener('keydown', (event) => {
    if (event.key === 'ArrowUp' || event.key === 'w' || event.key === 'W') {
        movePlayer('W');
    } else if (event.key === 'ArrowLeft' || event.key === 'a' || event.key === 'A') {
        movePlayer('A');
    } else if (event.key === 'ArrowDown' || event.key === 's' || event.key === 'S') {
        movePlayer('S');
    } else if (event.key === 'ArrowRight' || event.key === 'd' || event.key === 'D') {
        movePlayer('D');
    }
});

// Initial setup
updatePlayerPosition();

// Reset the game
function resetGame() {
    playerX = 0;
    playerY = 0;
    gameMode = 'playing';
    feedback.textContent = '';
    result.textContent = '';
    updatePlayerPosition();
}

// Event listener for the "Reset" button
document.getElementById('reset-button').addEventListener('click', resetGame);

// Call resetGame() to initialize the game
resetGame();
// Get a reference to the <audio> element
var audio = document.getElementById("myAudio");

// Play the audio
function playAudio() {
    audio.play();
}

// Pause the audio
function pauseAudio() {
    audio.pause();
}
// Adjust volume (0.0 to 1.0)
audio.volume = 0.5;

// Loop audio playback
audio.loop = true;

// Event listener for when audio playback ends
audio.addEventListener("ended", function() {
    console.log("Audio playback ended.");
});
var button = document.getElementById("playButton");
button.addEventListener("click", playAudio);

