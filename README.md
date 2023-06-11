# Othelo Game

## Google Drive Link

https://drive.google.com/drive/folders/1y-lzUNNT7c5vB33CE3t_wt26rvCI8eCq?usp=drive_link

## YouTube Vide link

https://youtu.be/tjPDnXre9Co

## Programming Language

The project is made with C++ and CLR library for the GUI
<br>
Tools used: Visual Studio 2019

## Supported Algorithm

The main algorithm used for the game playing is MinMax with alpha-beta pruning algorithm.
<br>
The first function used in thinking, is the aiThink() function, it’s purpose is to act as an entry point for the algorithm, it calulates all the possible moves from a single state, loop over them and call the minMaxAlphaBeta function
<br>
The main function is minMaxAlphaBeta which is a recursive function implementing the algorithm.

## Heuristics

They are based on main 3 metrics which are: <br>

- Mobility <br>
- Coin Parity <br>
- Corners Captured

## Features

1. The Game supports 3 modes

   - Human vs Human
   - Human vs Computer
   - Computer vs Computer

2. For the second and the third modes, the game supports 3 levels of difficulties

   - Easy
   - Medium
   - Hard

3. The game displays a top status bar that shows

   - The turn of the current user and his color
   - GameOver and who wins (or if it’s a tie)

4. The game supports displaying the score of both players, which is the number of coins on the board so far

5. A button for returning to the main menu to change the mode of playing or the difficulty and a button for restarting the game

6. The game also supports displaying hollow circles in the places of a all available moves in the next game

## Difficulty Levels

For the Easy mode => the max depth of the min max tree is 1 <br>
For the Medium mode => the max depth is 2 <br>
And for the Hard mode => the max depth is 5
