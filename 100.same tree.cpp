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


class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		stack<TreeNode *>sa, sb;
		bool res = true;

		if ((p == NULL || q == NULL) && p != q)return false;
		if (p == NULL && q == NULL)return true;
		sa.push(p);
		sb.push(q);
		while (!sa.empty() && !sb.empty())
		{
			TreeNode *topa = sa.top();
			sa.pop();
			TreeNode *topb = sb.top();
			sb.pop();

			
			if (isFalth(topa, topb))
			{
				res = false;
				break;
			}

			if (topa->right != NULL && topb->right != NULL)
			{
				sa.push(topa->right);
				sb.push(topb->right);
			}
			if (topa->left != NULL && topb->left != NULL)
			{
				sa.push(topa->left);
				sb.push(topb->left);
			}
		}
		return res;
	}

	//判断当前同一节点位置处值是否相等，以及下一层结构是否一致
	inline bool isFalth(TreeNode *a, TreeNode *b)
	{
		if (a->val != b->val)return true;
		if ((a->left == NULL || b->left == NULL) && a->left != b->left)return true;
		if ((a->right == NULL || b->right == NULL) && a->right != b->right)return true;
		return false;
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
	
	pd->left = pe;
	pd->right = pc;
	Solution so;
	cout << so.isSameTree(pa, pd) << endl;

	
	return 0;
}