/******************************************
problem:
Write a function to find the longest common prefix string amongst an array of strings.

author: guohongzhi

language: C
******************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) 
{
	if (strsSize == 0)return "";

	int minLen = INT_MAX;
	for (int i = 0; i < strsSize; ++i)
	{
		int len = strlen(strs[i]);
		if (len < minLen)minLen = len;
	}

	if (minLen == 0)return "";

	int endPos = 0;
	for (; endPos < minLen; ++endPos)
	{
		char c = strs[0][endPos];
		bool mark = true;
		for (int i = 0; i < strsSize; ++i)
		{
			if (strs[i][endPos] != c)
			{
				mark = false;
				break;
			}
		}
		if (!mark)break;
	}

	char *res = (char *)calloc(endPos + 1, sizeof(char));
	strncpy(res, strs[0], endPos);
	res[endPos] = '\0';
	return res;
}

int main()
{
	int strsSize = 2;
	char **str = (char **)calloc(strsSize, sizeof(char *));

	str[0] = (char *)calloc(4, sizeof(char));
	strncpy(str[0], "223", 3);

	str[1] = (char *)calloc(4, sizeof(char));
	strncpy(str[1], "12", 2);

	printf("%s\n", longestCommonPrefix(str, strsSize));
	return 0; 
}
