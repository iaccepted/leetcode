/******************************************
problem:
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

author: guohongzhi

language: C



******************************************/

#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int* nums, int numsSize) 
{
	int index = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] != 0)
		{
			nums[index++] = nums[i];
		}
	}
	
	for (int i = index; i < numsSize; ++i)
	{
		nums[i] = 0;
	}
}

int main()
{
	int nums[] = {0, 2, 0, 1, 3, 0, 0, 0, 4, 44};
	
	int numsSize = sizeof(nums) / sizeof(int);
	moveZeroes(nums, numsSize);
	
	for (int i = 0; i < numsSize; ++i)
	{
		printf("%d  ", nums[i]);
	}
	
	printf("%d\n");
	return 0;
}
