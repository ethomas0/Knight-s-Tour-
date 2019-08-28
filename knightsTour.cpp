// V2.SandBox1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int moveCounter = 1;
int totalTries = 0;
int badMoves = 0;
int board[8][8] = { 0 };
void printBoard(int board[][8], int size); // This is to print chess board
bool moveKnight(int verticalMove[], int horizontalMove[], int moveCounter); // this returns final answer
bool possibleSolution(int x, int y, int verticalMove[], int horizontalMove[], int moveCounter); // this checks if solution is possible from starting position
bool boundsCheck(int next_X_Move, int next_Y_Move); // checks if its within bounds

int main()
{
	int verticalMove[8] = { -2, -1, 1, 2, 2, 1, -1, -2};
	int horizontalMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	
	moveKnight(verticalMove, horizontalMove, moveCounter);
	printBoard(board, 8);

	

	system("pause");
    return 0;
}

void printBoard(int board[][8], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << setw(4) << board[i][j];
		}
		cout << endl;
	}
	cout << "Number of tries: " << badMoves << endl;
}


bool moveKnight(int verticalMove[], int horizontalMove[], int moveCounter) //returns true if possible solution exsist otherwise tells you not possible
{
	

	if (possibleSolution(0, 0, verticalMove, horizontalMove, moveCounter) == false)
	{
		cout << "Solution does not exist at this starting position" << endl;
		return false;
	}
	else
	{
		return true;
	}

	
}


bool possibleSolution(int x, int y, int verticalMove[], int horizontalMove[], int moveCounter) // check to see if solution is possible from chosen starting point
{
	int next_X_Move, next_Y_Move;
	board[x][y] = moveCounter;


	if (moveCounter == 64)
	{
		return true;
	}
	for (int i = 0; i < 8; i++)
	{
		next_X_Move = x + horizontalMove[i];
		next_Y_Move = y + verticalMove[i];

		if (boundsCheck(next_X_Move, next_Y_Move))
		{
			board[next_X_Move][next_Y_Move] = moveCounter+1;
			
			if (possibleSolution(next_X_Move, next_Y_Move, verticalMove, horizontalMove, moveCounter+1) == true)
			{
				return true;
			}
			else
			{
				board[next_X_Move][next_Y_Move] = 0;
			}
		}
	}
	
	++badMoves;
	return false;

}

bool boundsCheck(int next_X_Move, int next_Y_Move) // supposed to return true if it is within bounds
{
	return(next_X_Move >= 0 && next_X_Move < 8 && next_Y_Move >= 0 && next_Y_Move < 8 && board[next_X_Move][next_Y_Move] == 0);
}
