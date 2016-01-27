/******************************************
101. Symmetric Tree My Submissions Question
Total Accepted: 86593 Total Submissions: 264505 Difficulty: Easy
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

author: guohongzhi

language: C / C++

******************************************/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

/*
//递归的写法
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)return true;
		return judge(root->left, root->right);
	}

	bool judge(TreeNode *left, TreeNode *right)
	{
		if (right == NULL && left == NULL)return true;
		if ((right == NULL || left == NULL) && left != right)return false;
		return (right->val == left->val &&
			judge(left->left, right->right) && 
			judge(left->right, right->left));

	}
};
*/

//将递归的写法改成非递归的方式
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)return true;
		bool ret = true;
		stack<TreeNode *> st;
		st.push(root->left);
		st.push(root->right);
		TreeNode *l = NULL, *r = NULL;
		while (!st.empty())
		{
			//这里的r和l不是表示一个节点的左子树还是右子树
			//而是表示出来的点在整个根节点的左侧还是右侧
			r = st.top(), st.pop();
			l = st.top(), st.pop();

			if (r == NULL && l == NULL)continue;

			if ((r == NULL || l == NULL) && r != l)
			{
				ret = false;
				break;
			}
			
			if (r->val != l->val)
			{
				ret = false;
				break;
			}
			st.push(l->left);
			st.push(r->right);
			st.push(l->right);
			st.push(r->left);
		}
		return ret;
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *a = new TreeNode(2);
	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(4);
	TreeNode *d = new TreeNode(4);
	TreeNode *e = new TreeNode(6);
	TreeNode *f = new TreeNode(7);

	root->left = a;
	root->right = b;
	a->left = c;
	b->right = d;
	Solution so;

	bool ret = so.isSymmetric(root);

	cout << ret << endl;
	return 0;
}


