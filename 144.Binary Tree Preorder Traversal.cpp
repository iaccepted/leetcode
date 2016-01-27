/**************************************************************************
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

题目的意思就是给定一棵已经建好的二叉树，要求返回其前序输出序列，属于基本的
二叉树的数据结构题目.
**************************************************************************/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode *>st;
		
		if (root == NULL)return res;
		st.push(root);
		
		while (!st.empty())
		{
			TreeNode *node = st.top();
			st.pop();
			res.push_back(node->val);

			if (node->right != NULL)st.push(node->right);
			if (node->left != NULL)st.push(node->left);
		}
		return res;
	}
};

int main()
{
	TreeNode *pa, *pb, *pc;

	pa->val = 1;
	pb->val = 2;
	pc->val = 3;

	pa->right = pb;
	pb->left= pc;
	Solution so;
	so.preorderTraversal(pa);
	return 0;
}