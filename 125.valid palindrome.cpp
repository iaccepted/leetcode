/******************************************
problem:
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

author: guohongzhi

language: C



******************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(char* s)
{
	int len = strlen(s);
	char *str = (char *)calloc(len, sizeof(char));

	int index = 0;
	for (int i = 0; i < len; ++i)
	{
		if (('0' <= s[i] && s[i] <= '9') || ('a' <= s[i] && s[i] <= 'z'))
		{
			str[index++] = s[i];
		}
		else if ('A' <= s[i] && s[i] <= 'Z')
		{
			str[index++] = s[i] - 'A' + 'a';
		}
	}
	str[index] = '\0';
	len = index / 2;
	bool palindromeMark = true;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] != str[index - 1 - i])
		{
			palindromeMark = false;
			break;
		}
	}
	return palindromeMark;
}

int main()
{
	char *s = "race a car";
	printf("%d\n", isPalindrome(s));
	return 0; 
}
