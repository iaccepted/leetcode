/*****************************************************
99. Recover Binary Search Tree My Submissions Question
Total Accepted: 45274 Total Submissions: 178278 Difficulty: Hard
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
	void recoverTree(TreeNode *root)
	{
		vector<TreeNode *> res;
		stack<TreeNode *> st;
		TreeNode *p = root;

		while (p != NULL || !st.empty())
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
				res.push_back(top);
				p = top->right;
			}
		}
		//用来记录不符合规范的两个节点的指针
		//来自凌风博客www.iaccepted.net
		TreeNode *erra = NULL, *errb = NULL;
		int size = res.size();
		for (int i = 0; i < size - 1; ++i)
		{
			if (res[i]->val > res[i + 1]->val)
			{
				erra = res[i];
				break;
			}
		}

		for (int i = size - 1; i > 0; --i)
		{
			if (res[i]->val < res[i - 1]->val)
			{
				errb = res[i];
				break;
			}
		}

		//若不为空，直接交换就可以了
		if (erra != NULL && errb != NULL)
		{
			int tmp = erra->val;
			erra->val = errb->val;
			errb->val = tmp;
		}
	}
};


int main()
{
	TreeNode *pa, *pb, *pc, *pd, *pe;

	//pa = new TreeNode(1);
	pb = new TreeNode(4);
	pc = new TreeNode(3);
	pd = new TreeNode(2);
	//pe = new TreeNode(5);

	//pa->left = pb;
	//pa->right = pc;
	//pc->left = pd;
	//pc->right = pe;
	pc->left = pb;
	pc->right = pd;
	Solution so;
	so.recoverTree(pc);

	
	return 0;
}