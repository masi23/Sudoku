# SUDOKU
Welcome to Sudoku Game. It's a console application written in C language.

It lets you play 1 of 3 difficulty levels: `EASY`, `MEDIUM` and `HARD`. Each level differences in number of empty numbers to fill.

Making such project was on my mind for a long time, because from all logical games, I always enjoyed SUDOKU the most.

## Features
- **Random Puzzle Generation**: Each game starts with a randomly generated Sudoku board.
- **Three Difficulty Levels**: Choose from easy, medium, and hard. Each with a different number of cells removed.
- **Interactive Play**: Fill in the puzzle interactively and see if you can solve it. You can only make 3 mistakes.

## Getting Started
**1. Clone the Repository**
```
git clone https://github.com/masi23/Sudoku.git
cd Sudoku
```
**2. Compile the Program**
```
gcc -o sudoku.c -lm
```
**3. Run the Program**

Choose `New Game` or `Exit`

**4. Choose Difficulty Level**

Choose one of presented difficulty levels by typing a number

**5. Choose Cell Position**

You can only choose empty cells. Pattern for typing position is:
letter from A to I as a column, number from 1 to 9 as row.
For example: `A1`, `C5`, `I9`, etc.

**6. Type in a number**

Type in a number from 1 to 9. If it doesn't fit in specified cell, the program will warn you about this mistake.

After the 3rd mistake, the game is over.

## License
This project is licensed under the MIT License. So you can use it as you want.

## Future Ideas
I see an opportunity to add some more features, such as time measuring, or even saving records of wins and losses in a file and then processing it in some way.
