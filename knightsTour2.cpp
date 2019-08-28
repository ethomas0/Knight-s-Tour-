//Name: Ethan Thomas
//Class: CS 132 Section: A
//Assignment: Knight's Tour Problem
//Description: This program will simulate the knight's tour problem in which the
//computer will move a knight chess piece from a starting point that has been 
// predetermined and will need to hit every spot only once. Once the computer 
//has completed this task it will print out the board and show you the move's
//it made. It also will print out the total amount of moves the computer
//tried and also how many bad moves it made.

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;




const int SIZE = 5;
const int ALL_Y_AXIS_MOVEMENTS[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int ALL_X_AXIS_MOVEMENTS[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
void printBoard(int board[][SIZE], int size, int totalTries, int badMoves); 
bool moveKnight( int const &moveCounter,int board[][SIZE],
				 int &totalTries, int &badMoves);
bool possibleSolution(int x, int y, int const &moveCounter, int board [][SIZE],
					  int &totalTries, int &badMoves);
bool boundsCheck(int x_Axis_Move, int y_Axis_Move, int board[][SIZE]);

int main()
{
	int badMoves = 0;
	int totalTries = 0;
	int moveCounter = 1;
	int board[SIZE][SIZE] = { 0 };
	
	
	moveKnight(moveCounter, board, totalTries,badMoves);
	printBoard(board, SIZE, totalTries, badMoves);

	

	system("pause");
    return 0;
}

//This funtion prints out the board results, along with total amount of tries
//and total amount of bad moves in which the computer had to backtrack.
void printBoard(int board[][SIZE], int size, int totalTries, int badMoves)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << setw(4) << board[i][j];
		}
		cout << endl;
	}
	cout << "Total Moves: " << totalTries << endl;
	cout << "Bad Moves: " << badMoves << endl;
}


//Checks at the selected starting point whether or not it is possible to complete
//the knight's tour from that starting point
bool moveKnight(int const &moveCounter, int board[][SIZE],
				int &totalTries, int &badMoves) 
{
	if (possibleSolution(0, 0, moveCounter, board, totalTries, badMoves)
		== false)
	{
		cout << "Solution does not exist at this starting position" << endl;
		return false;
	}
	else
	{
		return true;
	}	
}

//This actually starts the knight's tour in which in goes through 8 different
//moves it can make and determining if its within bounds of the chess board and
//the board space has not been touched yet. It also will back track if it gets
//stuck on the board
bool possibleSolution(int x, int y, int const &moveCounter, int board[][SIZE], 
					  int &totalTries, int &badMoves) 
{
	int x_Axis_Move, y_Axis_Move;
	board[x][y] = moveCounter;


	if (moveCounter == SIZE * SIZE)
	{
		return true;
	}
	for (int i = 0; i < 8; i++)
	{
		x_Axis_Move = x + ALL_X_AXIS_MOVEMENTS[i];
		y_Axis_Move = y + ALL_Y_AXIS_MOVEMENTS[i];
		++totalTries;

		if (boundsCheck(x_Axis_Move, y_Axis_Move, board))
		{
			board[x_Axis_Move][y_Axis_Move] = moveCounter+1;
			
			if (possibleSolution(x_Axis_Move, y_Axis_Move, moveCounter+1, board,
				totalTries, badMoves) == true)
			{
				return true;
			}
			else
			{
				board[x_Axis_Move][y_Axis_Move] = 0;
				++badMoves;
			}
		}
	}
	
	return false;
}

//This checks to make sure the move is still inside the chess board. 
//If so it will return true.

bool boundsCheck(int x_Axis_Move, int y_Axis_Move, int board[][SIZE]) 
{
	return(x_Axis_Move >= 0 && x_Axis_Move < SIZE && y_Axis_Move >= 0
		   && y_Axis_Move < SIZE && board[x_Axis_Move][y_Axis_Move] == 0);
}

//Output:
/*1  54  39  48  59  44  31  50
  38 47  56  53  32  49  60  43
  55  2  33  40  45  58  51  30
  34 37  46  57  52  25  42  61
  3  20  35  24  41  62  29  14
  36 23  18  11  26  15   8  63
  19  4  21  16   9   6  13  28
  22 17  10   5  12  27  64   7
  Total Moves : 25936253
  Bad Moves : 3242001*/
