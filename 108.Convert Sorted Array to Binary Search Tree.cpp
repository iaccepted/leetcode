/*****************************************************
108. Convert Sorted Array to Binary Search Tree
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
******************************************************/
#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) 
	{
		return buildBST(nums, 0, nums.size() - 1);
	}

	TreeNode *buildBST(vector<int> &nums, int l, int r)
	{
		if (l > r)return NULL;
		int m = (l + r) >> 1;
		TreeNode *root = new TreeNode(nums[m]);
		root->left = buildBST(nums, l, m - 1);
		root->right = buildBST(nums, m + 1, r);
		return root;
	}
};

int main()
{
	vector<int> nums = { 2, 5, 8, 10, 15, 21 };
	Solution so;
	TreeNode *root = so.sortedArrayToBST(nums);
	

	return 0;
}