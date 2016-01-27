/******************************************
117. Populating Next Right Pointers in Each Node II
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

author: guohongzhi

language: C / C++

******************************************/
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;


struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        vector<vector<TreeLinkNode *>> levels;
        levelOrder(root, 1, levels);

        int nlevel = levels.size();
        for (int i = 0; i < nlevel; ++i)
        {
            int nele = levels[i].size();
            for (int j = 0; j < nele - 1; ++j)
            {
                levels[i][j]->next = levels[i][j + 1];
            }
            levels[i][nele - 1] = NULL;
        }
    }

    void levelOrder(TreeLinkNode *root, int level, vector<vector<TreeLinkNode *>> &res)
    {
        if (root == NULL)return;
        if (level <= res.size())
        {
            res[level - 1].push_back(root);
        }
        else
        {
            vector<TreeLinkNode *> lvec;
            lvec.push_back(root);
            res.push_back(lvec);
        }
        levelOrder(root->left, level + 1, res);
        levelOrder(root->right, level + 1, res);
    }
};

int main()
{
    TreeLinkNode *root = new TreeLinkNode(1);
    TreeLinkNode *a = new TreeLinkNode(2);
    TreeLinkNode *b = new TreeLinkNode(2);
    TreeLinkNode *c = new TreeLinkNode(4);
    TreeLinkNode *d = new TreeLinkNode(3);
    TreeNode *e = new TreeNode(6);
    TreeNode *f = new TreeNode(7);

    root->left = a;
    root->right = b;
    a->left = c;
    b->right = d;
    
    Solution so;

    so.connect(root);

    cout << c->next->val << endl;
    return 0;
}


