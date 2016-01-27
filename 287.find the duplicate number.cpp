/******************************************
problem:
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate element must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant extra space.
Your runtime complexity should be less than O(n2).

author: guohongzhi

language: C
******************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int cmp(const void *pa, const void *pb)
{
	int *a = (int *)pa;
	int *b = (int *)pb;

	return (*a - *b);
}

int findDuplicate(int* nums, int numsSize) 
{
	qsort(nums, numsSize, sizeof(int), cmp);
	
	int res = 0;
	for (int i = 1; i < numsSize; ++i)
	{
		if (nums[i] == nums[i - 1])
		{
			res = nums[i];
			break;
		}
	}

	return res;
}


int main()
{
	int arr[] = { 1, 1, 1, 4, 3, 5 };

	int numsSize = sizeof(arr) / sizeof(int);

	printf("%d\n", findDuplicate(arr, numsSize));
	return 0; 
}
