/******************************************
problem:
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

author: guohongzhi

language: C
******************************************/

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

void fillRow(int **matrix, int colSize, int row)
{
	for (int i = 0; i < colSize; ++i)
	{
		matrix[row][i] = 0;
	}
}

void fillCol(int **matrix, int rowSize, int col)
{
	for (int i = 0; i < rowSize; ++i)
	{
		matrix[i][col] = 0;
	}
}
void setZeroes(int** matrix, int matrixRowSize, int matrixColSize)
{
	bool *rowNums = (bool *)calloc(matrixRowSize, sizeof(bool));
	bool *colNums = (bool *)calloc(matrixColSize, sizeof(bool));

	for (int i = 0; i < matrixRowSize; ++i)
	{
		for (int j = 0; j < matrixColSize; ++j)
		{
			if (matrix[i][j] == 0)
			{
				rowNums[i] = true;
				colNums[j] = true;
			}
		}
	}

	for (int i = 0; i < matrixRowSize; ++i)
	{
		if (rowNums[i])fillRow(matrix, matrixColSize, i);
		
	}
	for (int i = 0; i < matrixColSize; ++i)
	{
		if (colNums[i])fillCol(matrix, matrixRowSize, i);
	}
}



int main()
{
	int rowSize = 3, colSize = 4;

	int **matrix = (int **)calloc(rowSize, sizeof(int *));
	for (int i = 0; i < rowSize; ++i)
	{
		matrix[i] = (int *)calloc(colSize, sizeof(int));
		for (int j = 0; j < colSize; ++j)
		{
			matrix[i][j] = i * colSize + j + 1;
		}
	}
	matrix[0][2] = matrix[2][0] = 0;

	setZeroes(matrix, rowSize, colSize);

	for (int i = 0; i < rowSize; ++i)
	{
		for (int j = 0; j < colSize; ++j)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
