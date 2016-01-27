/******************************************
problem:
Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.

author: guohongzhi

language: C
******************************************/

#include <stdio.h>
#include <stdlib.h>

void reverseArray(int *nums, int size)
{
	for (int i = 0; i < size / 2; ++i)
	{
		int t = nums[i];
		nums[i] = nums[size - 1 - i];
		nums[size - 1 - i] = t;
	}
}

int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
    int *res = (int *)calloc(digitsSize + 1, sizeof(int));
    
    int c = 1;
    for (int i = 0; i < digitsSize; ++i)
    {
    	int tsum = digits[digitsSize - 1 - i] + c;
    	res[i] = tsum % 10;
    	c = tsum / 10;
    }
    
    *returnSize = digitsSize;
    if (c > 0)
    {
    	res[digitsSize] = c;
    	*returnSize = digitsSize + 1;
    }
    reverseArray(res, *returnSize);
    return res;
}

int main()
{
	int nums[] = {9, 9, 9, 9, 9, 9};
	int n = sizeof(nums) / sizeof(int);
	
	int newN;
	int *res = plusOne(nums, n, &newN);
	for (int i = 0; i < newN; ++i)
	{
		printf("%d  ", res[i]);
	}
	printf("\n");
	return 0;
}

