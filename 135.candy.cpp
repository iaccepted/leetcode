/******************************************
problem:
There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

author: guohongzhi

language: C
******************************************/

#include <stdio.h>
#include <stdlib.h>

int maxx(int a, int b)
{
	if (a > b)return a;
	return b;
}

int candy(int* ratings, int ratingsSize) 
{
	if (ratingsSize <= 0)return 0;
	int *candys = (int *)calloc(ratingsSize, sizeof(int));
	candys[0] = 1;
 	for (int i = 1; i < ratingsSize; ++i)
 	{
 		if (candys[i] > candys[i - 1])candys[i] = candys[i - 1] + 1;
 		else candys[i] = 1;
 	}
 	
 	for (int i = ratingsSize - 1; i > 0; --i)
 	{
 		if (candys[i- 1] > candys[i])candys[i] = maxx(candys[i] + 1, candys[i - 1]);
 	}
 	
 	int res = 0;
 	for (int i = 0; i < ratingsSize; ++i)
 	{
 		res += candys[i];
 	}
 	
 	return res;
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
