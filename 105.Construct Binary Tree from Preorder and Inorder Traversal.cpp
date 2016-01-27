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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return getRoot(inorder, 0, inorder.size() - 1, preorder, 0);
	}

	TreeNode *getRoot(vector<int> &inorder, int l, int r, vector<int> &preorder, int loc)
	{
		if (l > r)return NULL;
		int i = l;
		for (; i <= r; ++i)
		{
			if (preorder[loc] == inorder[i])break;
		}
		TreeNode *root = new TreeNode(preorder[loc]);
		//构建左子树
		root->left = getRoot(inorder, l, i - 1, preorder, loc + 1);
		//构建右子树，右子树的根节点在前序中的下标为当前下标加上左子树中节点个数然后+1
		root->right = getRoot(inorder, i + 1, r, preorder, loc + i - l + 1);
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
	
	vector<int> preorder = { 1, 4, 6, 3, 5 };
	vector<int> inorder = { 6, 4, 1, 3, 5 };

	Solution so;
	TreeNode *root = so.buildTree(preorder, inorder);

	cout << root->left->left->val << endl;
	cout << root->right->right->val << endl;

	return 0;
}
