/******************************************
problem:
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
A partially filled sudoku which is valid.
Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.The digits are stored such that the most significant digit is at the head of the list.

author: guohongzhi

language: C
******************************************/

#include <stdio.h>
#include <stdlib.h>

#define N 10

void setValue(bool *used, bool val)
{
	for (int i = 0; i < N; ++i)
	{
		used[i] = val;
	}
}

bool check(bool *used, char c)
{
	if (c == '.')return true;
	if (used[c - '0'])return false;
	used[c - '0'] = true;
	return true;
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) 
{
	bool used[N];
	
	//check each row
	for (int row = 0; row < boardRowSize; ++row)
	{
		setValue(used, false);
		for (int col = 0; col < boardColSize; ++col)
		{
			if (!check(used, board[row][col]))return false;
		}
	}
	
	//check each col
	for (int col = 0; col < boardColSize; ++col)
	{
		setValue(used, false);
		for (int row = 0; row < boardRowSize; ++row)
		{
			if (!check(used, board[row][col]))return false;
		}
	}
	
	//check each cell
	for (int ci = 0; ci < 3; ++ci)
	{
		for (int cj = 0; cj < 3; ++cj)
		{
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					int row = ci * 3 + i;
					int col = cj * 3 + j;
					if (!check(used, board[row][col]))return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	const char *s = ".876543212........3........4........5........6........7........8........9........";
	char **board = (char **)calloc(9, sizeof(char *));
	
	for (int i = 0; i < N - 1; ++i)
	{
		board[i] = (char *)calloc(9, sizeof(char));
		for (int j = 0; j < N - 1; ++j)
		{
			board[i][j] = s[i * 9 + j];
		}
	}
	
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < N - 1; ++j)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}