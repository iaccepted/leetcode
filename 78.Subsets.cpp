/**************************************************************************
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
**************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int> &nums)
	{
		this->n = nums.size();
		sort(nums.begin(), nums.end());

		vector<vector<int>> sets;
		vector<int> path;

		subsets(nums, 0, sets, path);
		return sets;
	}
private:
	void subsets(vector<int> &nums, int index, vector<vector<int>> &sets, vector<int> &path)
	{
		sets.push_back(path);
		for (int i = index; i < n; ++i)
		{
			path.push_back(nums[i]);
			subsets(nums, i + 1, sets, path);
			path.pop_back();
		}
	}

	int n;
};

int main()
{
	vector<int> nums = { 1, 2, 2, 2, 4 };

	Solution so;
	vector<vector<int>> sets = so.subsets(nums);

	for each(auto vec in sets)
	{
		for each(auto ele in vec)
		{
			cout << ele << "\t";
		}
		cout << endl;
	}
	return 0;
}