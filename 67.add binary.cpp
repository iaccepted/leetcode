/******************************************
problem:
Given two binary strings, return their sum (also a binary string).
For example,
a = "11"
b = "1"
Return "100".
author: guohongzhi

language: C
******************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *reverse(char *s, int n)
{
	for (int i = 0; i < n / 2; ++i)
	{
		char c = s[i];
		s[i] = s[n - 1 - i];
		s[n - 1 - i] = c;
	}
	return s;
}

char* addBinary(char* a, char* b) 
{
	int lena = strlen(a), lenb = strlen(b);

	int maxx = lena > lenb ? lena : lenb;
	char *res = (char *)calloc(maxx + 2, sizeof(char));

	int index = 0, c = 0;
	while (lena > 0 || lenb > 0)
	{
		short bita = 0, bitb = 0;
		if (lena > 0)
		{
			bita = a[lena - 1] - '0';
			--lena;
		}
		if (lenb > 0)
		{
			bitb = b[lenb - 1] - '0';
			--lenb;
		}
		res[index++] = (bita + bitb + c) % 2 + '0';
		c = (bita + bitb + c) / 2;
	}
	if (c != 0)res[index++] = c + '0';
	res[index] = '\0';
	return reverse(res, index);
}

int main()
{
	char sa[] = "1";
	char sb[] = "1";

	printf("%s\n", addBinary(sa, sb));
	return 0; 
}
