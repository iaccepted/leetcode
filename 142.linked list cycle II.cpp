/******************************************
problem:
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Note: Do not modify the linked list.
Follow up:
Can you solve it without using extra space?

author: guohongzhi

language: C

分析：
当 fast 与 slow 相遇时，slow 肯定没有遍历完链表，而 fast 已经在环内循环了 n 圈 (1 ≤ n)。假
设 slow 走了 s 步，则 fast 走了 2s 步（fast 步数还等于 s 加上在环上多转的 n 圈），设环长为 r，则：
2s = s + nr
s = nr
设整个链表长 L，环入口点与相遇点距离为 a，起点到环入口点的距离为 x，则
x + a = nr = (n–1)r + r = (n - 1)r + L-x
x = (n - 1)r + (L–x–a)
L–x–a 为相遇点到环入口点的距离，由此可知，从链表头到环入口点等于 n - 1 圈内环 + 相遇
点到环入口点，于是我们可以从 head 开始另设一个指针 slow2，两个慢指针每次前进一步，它俩
一定会在环入口点相遇。
******************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode 
{
	int val;
	struct ListNode *next;
}ListNode;

struct ListNode *detectCycle(struct ListNode *head) 
{
	struct ListNode *slow = head, *fast = head;
	bool cycleMark = false;
	
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			cycleMark = true;
			break;
		}
	}
	
	if (cycleMark)
	{
		struct ListNode *slowa = head;
		while(slowa != slow)slow = slow->next, slowa = slowa->next;
		return slow;
	}
	return NULL;
}

int main()
{
	
	struct ListNode a;
	struct ListNode b;
	struct ListNode c;
	struct ListNode d;
	
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &b;
	
	struct ListNode *res = detectCycle(&a);
	
	if (res == &b)
	{
		printf("YES\n");
	}
	else 
	{
		printf("NO\n");
	}
	return 0;
}
