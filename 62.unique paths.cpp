/******************************************
problem:
A robot is located at the top-left corner of a m x n grid (marked ‘Start’ in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.
******************************************/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/*滚动数组的方式***************************************
class Solution {
public:
	int uniquePaths(int m, int n) 
	{
		if (m * n <= 0)return 0;

		memset(nums, 0, sizeof(nums));
		nums[0] = 1;

		//当前点的路径数=上侧点的路径数+左侧点的路径数
		for (int i = 0; i < m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				nums[j] = nums[j] + nums[j - 1];
			}
		}
		return nums[n - 1];
	}

private:
	int nums[101];
};
******************************************************/

/*记忆化搜索的方式************************************
class Solution {
public:
	int uniquePaths(int m, int n) 
	{
		memset(nums, 0, sizeof(nums));
		return path(m, n);
	}

private:
	int nums[101][101];

	int path(int m, int n)
	{
		if (m * n <= 0)return 0;
		if (m == 1 || n == 1)return 1;
		int pa = nums[m - 1][n], pb = nums[m][n - 1];
		if (pa == 0)nums[m - 1][n] = path(m - 1, n);
		if (pb == 0)nums[m][n - 1] = path(m, n - 1);
		return nums[m - 1][n] + nums[m][n - 1];
	}
};
*****************************************************/
class Solution {
public:
	int uniquePaths(int m, int n) 
	{
		if (m * n <= 0)return 0;

		for (int i = 0; i <= m; ++i)
		{
			nums[i][0] = 1;
		}

		for (int j = 0; j <= n; ++j)
		{
			nums[0][j] = 1;
		}

		//当前点的路径数=上侧点的路径数+左侧点的路径数
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				nums[i][j] = nums[i - 1][j] + nums[i][j - 1];
			}
		}
		return nums[m - 1][n - 1];
	}

private:
	int nums[101][101];
};

int main()
{
	
	Solution so;
	cout << so.uniquePaths(1, 1) << endl;
	return 0;
}