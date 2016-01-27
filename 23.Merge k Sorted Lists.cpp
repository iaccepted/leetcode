/*******************************************************************
23.Merge k Sorted Lists
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*******************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;

struct cmp
{
    bool operator()(const ListNode *a, const ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode *>& lists)
    {
        auto ite = lists.begin();
        while (ite != lists.end()) {
            if (*ite == NULL)ite = lists.erase(ite);
            else ++ite;
        }
        
        if (lists.size() <= 0)return NULL;

        ListNode *head = new ListNode(-1);
        ListNode *tail = head;

        make_heap(lists.begin(), lists.end(), cmp());

        while (lists.size() > 0)
        {
            pop_heap(lists.begin(), lists.end(), cmp());
            int last = lists.size();
            tail->next = lists[last - 1];
            tail = tail->next;
            if (lists[last - 1]->next != NULL)
            {
                lists[last - 1] = lists[last - 1]->next;
                push_heap(lists.begin(), lists.end(), cmp());
            }
            else lists.pop_back();
        }
        return head->next;
    }   
};

int main()
{
    ListNode *pa, *pb, *pc, *pd, *pe;
    pa = new ListNode(1);
    pb = new ListNode(2);
    pc = new ListNode(3);
    pd = new ListNode(4);
    pe = new ListNode(10);


    vector<ListNode *> lists = { NULL };

    Solution so;
    ListNode *l = so.mergeKLists(lists);

    while (l != NULL)
    {
        cout << l->val << "\t";
        l = l->next;
    }
    cout << endl;
}