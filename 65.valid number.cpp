/******************************************
problem:
Validate if a given string is numeric.
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

author: guohongzhi

language: C
******************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef enum
{
	INVALID,  //0
	SPACE,    //1
	SIGN,     //2
	DIGIT,    //3
	DOT,      //4
	EXPONENT, //5
	NUMSTATES
}InputType;

//the main
int tables[][NUMSTATES] =
{
	-1, 0, 1, 2, 3, -1,   //0
	-1, -1, -1, 2, 3, -1, //1
	-1, 8, -1, 2, 4, 5,   //2
	-1, -1, -1, 4, -1, -1, //3
	-1, 8, -1, 4, -1, 5,  //4
	-1, -1, 7, 6, -1, -1, //5
	-1, 8, -1, 6, -1, -1, //6
	-1, -1, -1, 6, -1, -1, //7
	-1, 8, -1, -1, -1, -1 //8
};

bool isNumber(char *s)
{
	int len = strlen(s);
	if (len == 0)return false;

	int state = 0;
	InputType type;
	for (; *s != '\0'; ++s)
	{
		if (*s == ' ')type = SPACE;
		else if (*s >= '0' && *s <= '9')type = DIGIT;
		else if (*s == '.')type = DOT;
		else if (*s == 'e')type = EXPONENT;
		else if (*s == '+' || *s == '-')type = SIGN;
		else type = INVALID;

		state = tables[state][type];

		if (state == -1)return false;
	}

	if (state == 2 || state == 4 || state == 6 || state == 8)return true;
	else return false;
}

int main()
{
	
	char s[100];
	while (scanf("%s", s))
	{
		printf("%d\n", isNumber(s));
	}
	return 0; 
}
