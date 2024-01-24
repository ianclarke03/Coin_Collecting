# Coin Collector Game

Welcome to my coin-collecting game! In this game, you control a robot that aims to collect as many coins as possible to achieve the highest score. Coins are randomly generated on the screen, and you have the ability to grab multiple coins simultaneously.

## Game Mechanics

### Player Character
- You play as a robot navigating the game environment.
- Control the robot's movement using the arrow keys.

### Coin Collection
- Coins are randomly generated on the screen.
- The game includes a Coin class to manage coin properties.
- Utilizes collision functions to detect and record collisions in the game.
- The random nature of these functions allows for the possibility of picking up multiple coins at once with a single touch.

### Scoring System
- Each collision increments a score count displayed in the top-left corner.
- The score is represented using images from the "digits_folder" in the "Assets/Pictures" directory.
- The conversion process involves converting the current score from an integer to a string. For each character in the string, it is converted back to its corresponding number PNG image. The conversion process is similar to converting a char to an int by subtracting the value of '0'.

## Code Structure

To implement these features, two new files were added to the Game_IC folder:
1. `MyGame.h`: Header file containing declarations and class definitions.
2. `MyGame.cpp`: Implementation file with the logic for coin generation, collision detection, and scoring.

## Controls

- Use the arrow keys to move the robot around the game environment.
- Make strategic moves to collect as many coins as possible and achieve a high score.

## Build Instructions

1. Clone the repository.
2. Compile the source files, including `MyGame.h` and `MyGame.cpp`.
3. Run the executable to start playing the coin collector game.

Enjoy the game and have fun collecting coins with your robot!
