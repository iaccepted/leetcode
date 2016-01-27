/******************************************
problem:
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

author: guohongzhi

language: C
******************************************/

#include <stdio.h>
#include <stdlib.h>

int minx(int a, int b)
{
	if ( a < b)return a;
	return b;
}

int trap(int* height, int heightSize) 
{
	if (heightSize <= 0)return 0;
  int *maxLeft = (int *)calloc(heightSize, sizeof(int));
  int *maxRight = (int *)calloc(heightSize, sizeof(int));
  
  maxLeft[0] = height[0];
  maxRight[heightSize - 1] = height[heightSize - 1];
   
  for (int i = 1; i < heightSize; ++i)
  {
   	if (height[i] > maxLeft[i - 1])maxLeft[i] = height[i];
   	else maxLeft[i] = maxLeft[i - 1];
   		
   	if (height[heightSize - 1 - i] > maxRight[heightSize - i])maxRight[heightSize - 1 - i] = height[heightSize - 1 - i];
   	else maxRight[heightSize - 1 - i] = maxRight[heightSize - i];
  }
  
  int rainWater = 0;
  for (int i = 1; i < heightSize; ++i)
  {
  	rainWater += minx(maxLeft[i], maxRight[i]) - height[i];
  }
  free(maxLeft);
  free(maxRight);
  return rainWater;
}

int main()
{
	int nums[] = {9, 9, 9, 9, 9, 9};
	int n = sizeof(nums) / sizeof(int);
	
	int rainWater = trap(nums, n);
	printf("%d\n", rainWater);
	return 0;
}

