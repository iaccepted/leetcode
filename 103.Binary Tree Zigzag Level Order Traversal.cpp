
/*************************************************************
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
本题也是一个二叉树求层序遍历结果的题目，这里不同的是题目要求，结果是zigzag的形式，
也就是说相邻层的遍历方向不同，比如第一层为从左到右，那么第二层就是从右到左的遍历。
解题思路可以有几种，一种是在遍历的时候就直接处理不同的顺序，还有一种是正常的程序
遍历，然后最后对结果进行处理，把某些层（需要从右到左的层）逆置一下，从而实现倒序。
本题中采用了第二种方式，这样代码简介明了。题目如下：
****************************************************************/
AC代码如下：

#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<TreeNode *> current, next;
        vector<vector<int>> res;
        vector<int> lvec;

        if (root == NULL)return res;
        current.push_back(root);
        while (!current.empty())
        {
            int size = current.size();
            
            for (int i = 0; i < size; ++i)
            {
                TreeNode *ele = current[i];
                lvec.push_back(ele->val);
                if (ele->left != NULL)next.push_back(ele->left);
                if (ele->right != NULL)next.push_back(ele->right);  
            }
    
            if (!lvec.empty())
            {
                res.push_back(lvec);
            }
            current.swap(next);
            next.clear();
            lvec.clear();
        }

        //对奇数层进行反转来达到zigzag的效果
        int size = res.size();
        for (int i = 0; i < size; ++i)
        {
            if ((i % 2) == 1)
            {
                reverse(res[i].begin(), res[i].end());
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
    b->right = d;
    Solution so;

    vector<vector<int>> res = so.zigzagLevelOrder(root);

    for each (auto var in res)
    {
        for each(auto ele in var)
        {
            cout << ele << "\t";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}