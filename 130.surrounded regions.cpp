/******************************************
problem:
130. Surrounded Regions My Submissions Question

Given a 2D board containing ‘X’ and ‘O’, capture all regions surrounded by ‘X’.

A region is captured by flipping all ‘O’s into ‘X’s in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
******************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <unordered_set>

using namespace std;

const int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

class Solution {
public:
	void solve(vector<vector<char>> &board) 
	{
		if (board.size() <= 2)return;
		int rows = board.size();
		int cols = board[0].size();
		for (int i = 0; i < rows; ++i)
		{
			bfs(board, rows, cols, i, 0);
			bfs(board, rows, cols, i, cols - 1);
		}

		for (int i = 0; i < cols; ++i)
		{
			bfs(board, rows, cols, 0, i);
			bfs(board, rows, cols, rows - 1, i);
		}

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (board[i][j] == 'O')board[i][j] = 'X';
				else if (board[i][j] == 'U')board[i][j] = 'O';
			}
		}
	}

private:
	void bfs(vector<vector<char>> &board, int &rows, int &cols, int r, int c)
	{
		queue<int> que;
		que.push(r);
		que.push(c);

		int i, j;

		while (!que.empty())
		{
			i = que.front();
			que.pop();
			j = que.front();
			que.pop();

			if (i < 0 || i >= rows || j < 0 || j >= cols)continue;
			if (board[i][j] == 'X' || board[i][j] == 'U')continue;
			board[i][j] = 'U';
			
			for (int cnt = 0; cnt < 4; ++cnt)
			{
				que.push(i + dir[cnt][0]);
				que.push(j + dir[cnt][1]);
			}
		}
	}
};

void print(vector<vector<char>> &board)
{
	for each (auto vec in board)
	{
		for each(auto c in vec)
		{
			cout << c << " ";
		}
		cout << endl;
	}
}

int main()
{
	Solution so;
	//vector<vector<char>> board = { { 'X', 'X', 'X', 'X' }, { 'X', 'O', 'O', 'X' }, { 'X', 'O', 'O', 'X' }, { 'X', 'O', 'X', 'X' } };
	vector<vector<char>> board = { { 'X', 'O', 'X' }, { 'X', 'O', 'X' }, { 'X', 'O', 'X' } };

	print(board);
	so.solve(board);
	cout << "---------------------------------" << endl;
	print(board);
	
	return 0;
}
