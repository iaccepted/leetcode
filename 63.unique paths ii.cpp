/******************************************
problem:
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
******************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
	{
		if (obstacleGrid.empty() || obstacleGrid[0].empty())return 0;
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		memset(nums, 0, sizeof(nums));
		nums[0] = 1;

		if (obstacleGrid[0][0] == 1)nums[0] = 0;

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (obstacleGrid[i][j] == 1)nums[j] = 0;
				else
				{
					if (j > 0)nums[j] += nums[j - 1];
				}
			}
		}
		return nums[n - 1];
	}

private:
	int nums[101];
};

int main()
{
	vector<vector<int>> grid = { { 0 }, { 1 } };
	Solution so;
	cout << so.uniquePathsWithObstacles(grid) << endl;
	return 0;
}