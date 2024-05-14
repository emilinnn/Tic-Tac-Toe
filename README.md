# Tic-Tac-Toe Game

## Overview
This project is a simple Tic-Tac-Toe game implemented in C++. The game allows two players to play against each other or a single player to play against an AI opponent.

## Features
- **3x3 game board:** The game board is represented using a 2D array and displayed to the user after each move with enhanced visuals.
- **User input:** The program prompts the user to enter the row and column numbers of the cell they wish to mark and validates the input. The user can enter their move as two numbers separated by space or as a two-digit number.
- **Game rules:** The program enforces the rules of Tic-Tac-Toe, detects winning combinations, and announces the winner or a tie.
- **Two-player mode:** Two players can play against each other, taking turns to mark cells on the game board.
- **AI opponent mode:** A single player can play against an AI opponent using a simple algorithm to select the next move.
- **Exception handling:** The program handles runtime exceptions such as invalid user input.
- **User interface:** The game board and user prompts are displayed in a clear and understandable manner with enhanced visuals using ANSI escape codes.


## How to Run
1. Clone the repository.
2. Compile the program using a C++ compiler:
    ```sh
    g++ -o tic-tac-toe main.cpp
    ```
3. Run the executable:
    ```sh
    ./tic-tac-toe
    ```

## Explanation
In this game, you need to get three of your marks in a row to win. You can enter your move as two numbers separated by space or as a two-digit number. For example, to mark the top left corner, you can enter '1 1' or '11'.
