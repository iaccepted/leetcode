/******************************************
problem:
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

author: guohongzhi

language: C
******************************************/

#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n) 
{
    if (n <= 2)return n;
    int a = 1, b = 2, res = 0;
    for (int i = 2; i < n; ++i)
    {
    	res = a + b;
    	a = b;
    	b = res;
    }
    return res;
}

int main()
{
	int res = climbStairs(3);
	printf("%d\n", re]);
	return 0;
}

