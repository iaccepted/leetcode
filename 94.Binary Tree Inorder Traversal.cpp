/******************************************
problem:
Given a binary tree, return the inorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
1
 \
  2
 /
3
return [1,3,2].
Note: Recursive solution is trivial, could you do it iteratively?

author: guohongzhi

language: C / C++

******************************************/

/*c++*/
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode *> st;

		if (root == NULL)return res;

		TreeNode *p = root;
		while (!st.empty() || p != NULL)
		{
			if (p != NULL)
			{
				st.push(p);
				p = p->left;
			}
			else
			{
				TreeNode *top = st.top();
				st.pop();
				res.push_back(top->val);
				p = top->right;
			}
		}
		return res;
	}
};


int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *a = new TreeNode(2);
	TreeNode *b = new TreeNode(3);
	TreeNode *c = new TreeNode(4);
	TreeNode *d = new TreeNode(5);
	TreeNode *e = new TreeNode(6);
	TreeNode *f = new TreeNode(7);

	root->left = a;
	root->right = b;
	a->left = c;
	a->right = d;
	b->left = e;
	b->right = f;
	Solution so;

	vector<int> res = so.inorderTraversal(root);

	for each (auto i in res)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
