/******************************************
problem:
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
author: guohongzhi

language: C
******************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int integer[] = { 1000, 900, 500, 400, 100, 90,
50, 40, 10, 9, 5, 4, 1 };
const char roman[][3] = { "M", "CM", "D", "CD", "C", "XC",
"L", "XL", "X", "IX", "V", "IV", "I" };

char* intToRoman(int num) 
{
	int n = sizeof(integer) / sizeof(int);
	char *res = (char *)calloc(100, sizeof(char));
	int index = 0;

	for (int i = 0; i < n; ++i)
	{
		int cnt = num / integer[i];
		num %= integer[i];
		while (cnt--)
		{
			strcpy(res + index, roman[i]);
			index += strlen(roman[i]);
		}
	}
	res[index] = '\0';
	return res;
}

int main()
{
	printf("%s\n", intToRoman(3452));
	return 0; 
}
