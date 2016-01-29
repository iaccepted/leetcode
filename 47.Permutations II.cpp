/*************************************************************************
47. Permutations II

Total Accepted: 60496 Total Submissions: 222859 Difficulty: Medium
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int> &nums)
	{
		vector<vector<int>> res;
		if (nums.empty())return res;
		sort(nums.begin(), nums.end());
		res.push_back(nums);
		while (has_next(nums))
		{
			res.push_back(nums);
		}
		return res;
	}

private:
	bool has_next(vector<int> &nums)
	{
		int parLoc = nums.size() - 2;

		while (parLoc >= 0)
		{
			if (nums[parLoc] < nums[parLoc + 1])break;
			--parLoc;
		}

		if (parLoc < 0)return false;

		int rloc = nums.size() - 1;
		while (nums[rloc] <= nums[parLoc])--rloc;
		swap(nums[rloc], nums[parLoc]);
		reverse(nums.begin() + parLoc + 1, nums.end());
		return true;
	}
};

int main()
{
	vector<int> nums = { 1, 1, 2 };

	Solution so;
	vector<vector<int>> res = so.permuteUnique(nums);

	for each (auto vec in res)
	{
		for each (auto ele in vec)
		{
			cout << ele << "\t";
		}
		cout << endl;
	}
	return 0;
}