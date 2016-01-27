/*****************************************************
111. Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
	int minDepth(TreeNode* root) {
		if (root == NULL)return 0;
		int leftDepth = minDepth(root->left);
		int rightDepth = minDepth(root->right);
		//这个地方加一个判断，防止该节点不是叶结点而他有个子树为空的时候得出该结点的左右子树
		//中的最小深度为0，其实应该为不空的子树深度
		if (leftDepth == 0 || rightDepth == 0)return (leftDepth + rightDepth) + 1;
		if (leftDepth < rightDepth)return leftDepth + 1;
		return rightDepth + 1;
	}
};
