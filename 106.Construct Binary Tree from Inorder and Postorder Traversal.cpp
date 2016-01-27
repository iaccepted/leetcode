/****************************************************************************
题目如下：
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return getRoot(inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1);
	}

	TreeNode *getRoot(vector<int> &inorder, int l, int r, vector<int> &postorder, int loc)
	{
		if (l > r)return NULL;
		int i = l;
		for (; i <= r; ++i)
		{
			if (postorder[loc] == inorder[i])break;
		}
		TreeNode *root = new TreeNode(postorder[loc]);
		root->right = getRoot(inorder, i + 1, r, postorder, loc - 1);
		root->left = getRoot(inorder, l, i - 1, postorder, loc - (r - i + 1));
		return root;
	}
};

int main()
{
	TreeNode *pa, *pb, *pc, *pd, *pe;

	pa = new TreeNode(1);
	pb = new TreeNode(4);
	pc = new TreeNode(3);
	pd = new TreeNode(6);
	pe = new TreeNode(5);

	pa->left = pb;
	pa->right = pc;

	pb->left = pd;
	pc->right = pe;
	
	vector<int> postorder = { 4, 6, 5, 3, 2, 1 };
	vector<int> inorder = { 4, 5, 6, 1, 2, 3 };

	Solution so;
	TreeNode *root = so.buildTree(inorder, postorder);

	cout << root->left->left->val << endl;
	cout << root->right->right->val << endl;

	return 0;
}
