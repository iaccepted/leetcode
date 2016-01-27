/*****************************************************
100. Same Tree My Submissions Question
Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
******************************************************/
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
	int numTrees(int n) {
		int *res = new int[n + 1];
		res[0] = res[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			res[i] = 0;
			for (int j = 0; j < i; ++j)
			{
				res[i] += res[j] * res[i - 1 - j];
			}
		}
		int t = res[n];
		delete[] res;
		return t;
	}
};

int main()
{
	Solution so;
	int n = so.numTrees(3);

	cout << n << endl;

	return 0;
}
