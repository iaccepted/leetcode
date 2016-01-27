/*************************************************************
34. Search for a Range
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int> &nums, int target) 
	{
		int n = nums.size();
		int left = lower_bound(nums, target);
		int right = upper_bound(nums, target);

		if (nums[left] != target)return vector<int>{-1, -1};
		if (nums[right] != target)return vector<int>{left, right - 1};
		return vector<int>{left, right};
		
	}
private:
	int lower_bound(vector<int> &nums, int target)
	{
		int n = nums.size();
		int left = 0, right = n - 1;
		while (left < right)
		{
			int mid = (left + right) >> 1;
			if (nums[mid] < target)left = mid + 1;
			else right = mid;
		}
		return left;
	}

	int upper_bound(vector<int> &nums, int target)
	{
		int n = nums.size();
		int left = 0, right = n - 1;
		while (left < right)
		{
			int mid = (left + right) >> 1;
			if (nums[mid] <= target)left = mid + 1;
			else right = mid;
		}
		return left;
	}
};

int main()
{
	vector<int> nums = { 1 };
	Solution so;
	vector<int> res = so.searchRange(nums, 1);
	cout << res[0] << "\t" << res[1] << endl;
	return 0;
}
