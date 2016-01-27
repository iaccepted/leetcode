/*****************************************************
100. Same Tree My Submissions Question
Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
******************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

typedef struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

//思路：对于任意一个节点，将其右子树挂在其左子树上最右的节点下，然后
//将左子树挂在右指针，并把左指针置空,时间O(n*logn),空间O(1)
//class Solution {
//public:
//	void flatten(TreeNode* root) {
//		while (root != NULL)
//		{
//			if (root->left == NULL)
//			{
//				root = root->right;
//				continue;
//			}
//			TreeNode *right = root->right;
//			TreeNode *p = root->left;
//			root->right = root->left;
//			root->left = NULL;
//
//			while (p->right != NULL)p = p->right;
//		
//			p->right = right;
//			root = root->right;
//		}
//	}
//};

//思路：把右子树先暂存，处理完所有左子树之后，把右子树挂在最后
//所有节点迭代的执行下去时间O(n),空间O(n)
class Solution {
public:
	void flatten(TreeNode *root)
	{
		stack<TreeNode *> st;
		if (root == NULL)return;
		st.push(root);
		while (!st.empty())
		{
			root = st.top();
			st.pop();

			if (root->right != NULL)st.push(root->right);
			if (root->left != NULL)st.push(root->left);

			if (!st.empty())
			{
				root->right = st.top();
				root->left = NULL;
			}
		}
	}
};


int main()
{
	TreeNode *pa, *pb, *pc, *pd, *pe;

	pa = new TreeNode(1);
	pb = new TreeNode(4);
	pc = new TreeNode(3);
	pd = new TreeNode(1);
	pe = new TreeNode(5);

	pa->left = pb;
	pa->right = pc;
	pb->left = pd;
	pc->right = pe;
	
	Solution so;
	so.flatten(pa);

	while (pa != NULL)
	{
		cout << pa->val << "\t";
		pa = pa->right;
	}

	
	return 0;
}