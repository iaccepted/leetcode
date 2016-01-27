/******************************************
problem:
Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­
You must do this in-place without altering the nodes' values.
For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

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

void reorderList(struct ListNode* head)
{
	if (head == NULL)return;
	struct ListNode *evenHead = (struct ListNode *)malloc(sizeof(struct ListNode));
	evenHead->next = NULL;

	struct ListNode *p = head;
	int cnt = 1;
	while (p->next != NULL)
	{
		++cnt;
		p = p->next;
	}

	cnt = (cnt + 1) / 2;
	p = head;
	for (int i = 1; i < cnt; ++i)p = p->next;
	struct ListNode *t = p->next;
	p->next = NULL;
	p = t;
	while (p != NULL)
	{
		t = p->next;
		p->next = evenHead->next;
		evenHead->next = p;
		p = t;
	}

	struct ListNode *res = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *tail = res;
	struct ListNode *ta = NULL, *tb = NULL;

	ta = evenHead;
	evenHead = evenHead->next;
	free(ta);
	while (evenHead != NULL)
	{
		ta = head->next;
		tb = evenHead->next;
		tail->next = head;
		tail = tail->next;
		tail->next = evenHead;
		tail = tail->next;
		head = ta;
		evenHead = tb;
	}
	if (head != NULL)
	{
		tail->next = head;
		tail = head;
	}
	tail->next = NULL;
	free(res);
}

int main()
{

	struct ListNode a;
	struct ListNode b;
	struct ListNode c;
	struct ListNode d;

	a.val = 1;
	b.val = 2;
	c.val = 3;
	d.val = 4;

	a.next = &b;
	b.next = &c;
	c.next = NULL;
	//c.next = &d;
	//d.next = NULL;

	reorderList(&a);

	struct ListNode *t = &a;
	while (t != NULL)
	{
		printf("%d ", t->val);
		t = t->next;
	}
	printf("\n");
	return 0;
}
