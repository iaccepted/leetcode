/******************************************
problem:
Given a linked list, determine if it has a cycle in it.
Follow up:
Can you solve it without using extra space?

author: guohongzhi

language: C



******************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int val;
	struct ListNode *next;
}ListNode;

bool hasCycle(struct ListNode *head) 
{
	struct ListNode *slow = head, *fast = head;
	bool res = false;
	
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			res = true;
			break;
		}
	}
	return res;
}


int main()
{
	ListNode a, b, c, d, e;
	
	a.next = b;
	b.next = c;
	c.next = d;
	d.next = b;
	
	bool res = hasCycle(&a);
	
	if (res)
	{
		printf("YES\n");
	}
	else 
	{
		printf("NO\n");
	}
	return 0;
}
