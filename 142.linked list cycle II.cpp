/******************************************
problem:
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Note: Do not modify the linked list.
Follow up:
Can you solve it without using extra space?

author: guohongzhi

language: C

������
�� fast �� slow ����ʱ��slow �϶�û�б����������� fast �Ѿ��ڻ���ѭ���� n Ȧ (1 �� n)����
�� slow ���� s ������ fast ���� 2s ����fast ���������� s �����ڻ��϶�ת�� n Ȧ�����軷��Ϊ r����
2s = s + nr
s = nr
���������� L������ڵ������������Ϊ a����㵽����ڵ�ľ���Ϊ x����
x + a = nr = (n�C1)r + r = (n - 1)r + L-x
x = (n - 1)r + (L�Cx�Ca)
L�Cx�Ca Ϊ�����㵽����ڵ�ľ��룬�ɴ˿�֪��������ͷ������ڵ���� n - 1 Ȧ�ڻ� + ����
�㵽����ڵ㣬�������ǿ��Դ� head ��ʼ����һ��ָ�� slow2��������ָ��ÿ��ǰ��һ��������
һ�����ڻ���ڵ�������
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
