/*****************************************************
104. Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
******************************************************/
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL)return 0;
		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);
		if (leftDepth > rightDepth)return leftDepth + 1;
		return rightDepth + 1;
	}
};