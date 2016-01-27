/*****************************************************
109. Convert Sorted List to Binary Search Tree
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
******************************************************/

代码如下：

#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		vector<int> nums;
		while (head != NULL)
		{
			nums.push_back(head->val);
			head = head->next;
		}

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