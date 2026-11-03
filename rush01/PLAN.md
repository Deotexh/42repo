Here's our plan for rush01.

# Here are the steps the program have to go through that we were able to find:
1. Input string of clues
2. Convert those into int
3. Parse with error check
4. Create the board
5. Handle duplicates
6. Handle clues
7. Print board

# Here are the problems we have find for now:

##Prog
- How to choose board size?

##Parser
- How to adapt it to the size of the board?
- How to handle if the input is incorrect?

##Duplicates
- How to check rows?
- How to check columns?
- How to remember if we already encountered a digit once, per row/column
- How to handle when invalid?
- How to make it work with Clues System

##Clues
- How to validate them?
	- How to calculate
- How to make it work with Duplicates System

# Here are possible solutions for now:

##Generals

- Skyscraper game
- Sudoku game

##Specifics

###Prog

###Parser

###Duplicates
- 

###Clues
- Check for patterns on opposite-sided clues
	I've seen that when there's a 4 on a side, the opposite must be 1.	

#Roles

Viacheslav: Input of string, create board
Victor: Convert string into int
Karim: Handle errors in parse
