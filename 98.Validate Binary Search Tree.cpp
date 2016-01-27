/****************************************************************************
题目如下：
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
****************************************************************************/

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
	bool isValidBST(TreeNode* root) 
	{
		long long lower = INT_MIN, upper = INT_MAX;
		return isValid(root, lower - 1, upper + 1);
	}

	bool isValid(TreeNode *root, long long lower, long long upper)
	{
		if (root == NULL)return true;
		return ((root->val > lower && root->val < upper)
			&& isValid(root->left, lower, root->val)
			&& isValid(root->right, root->val, upper));
	}
};

int main()
{
	TreeNode *pa, *pb, *pc, *pd, *pe;

	pa = new TreeNode(4);
	pb = new TreeNode(3);
	pc = new TreeNode(5);
	pd = new TreeNode(1);
	pe = new TreeNode(5);

	pa->left = pb;
	pa->right = pc;
	Solution so;
	bool ret = so.isValidBST(NULL);
	cout << ret << endl;

	long long a = INT_MAX;
	cout << a + 2 << endl;
	return 0;
}
