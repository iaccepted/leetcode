/******************************************
problem:
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

author: guohongzhi

language: C
******************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int minx(int a, int b)
{
	if (a < b)return a;
	return b;
}

char* longestPalindrome(char* s) 
{
	int len = strlen(s);
	if (len <= 1)return s;
	char *str = (char *)calloc(2 * len + 3, sizeof(char));
	int *p = (int *)calloc(2 * len + 3, sizeof(int));

	int id = 0, mx = 1;
	str[0] = '$', str[2 * len + 1] = '#', str[2 * len + 2] = '\0';

	for (int i = 0; i < len; ++i)
	{
		str[2 * i + 2] = s[i];
		str[2 * i + 1] = '#';
	}

	int res = -1, mid = 0;
	for (int i = 2; i <= 2 * len; ++i)
	{
		if (i < mx)
		{
			p[i] = minx(p[2 * id - i], mx - i);
		}
		else
		{
			p[i] = 1;
		}

		while (str[i + p[i]] == str[i - p[i]])++p[i];
		if (p[i] > res)
		{
			res = p[i];
			mid = i;
		}
		if (i + p[i] > mx)
		{
			id = i;
			mx = i + p[i];
		}
	}
	char *dest = (char *)calloc(res, sizeof(char));
	strncpy(dest, s + (mid - res) / 2, res - 1);
	free(p);
	free(str);
	return dest;
}

int main()
{
	char *s = "1";
	printf("%s\n", longestPalindrome(s));
	return 0; 
}
