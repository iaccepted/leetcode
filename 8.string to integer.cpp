/******************************************
problem:
Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
spoilers alert... click to show requirements for atoi.
Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

author: guohongzhi

language: C
******************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int myAtoi(char* str) 
{
	int len = strlen(str);
	if (len == 0)return 0;

	int sign = 1;
	int i = 0;
	while (str[i] == ' ')++i;
	if (i == len)return 0;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')++i;

	long long res = 0;
	while (i < len && '0' <= str[i] && str[i] <= '9')
	{
		res *= 10;
		res += sign * (str[i] - '0');
		if (res > INT_MAX)
		{
			res = INT_MAX;
			break;
		}
		else if (res < INT_MIN)
		{
			res = INT_MIN;
			break;
		}
		++i;
	}
	return res;
}

int main()
{
	int res = myAtoi("9223372036854775809");
	printf("%d\n", res);
	return 0; 
}
