/******************************************
problem:
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
Some examples:
["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

author: guohongzhi

language: C / C++

note:
string 转int可以直接使用标准库函数stoi(string)来完成而不用自己实现
******************************************/

/*c++*/
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> res;
		int size = tokens.size();

		for (int i = 0; i < size; ++i)
		{
			if (isOperator(tokens[i]))
			{
				int b = res.top();
				res.pop();
				int a = res.top();
				res.pop();

				int ans = calculate(a, b, tokens[i]);
				res.push(ans);
			}
			else
			{
				//这里可以直接使用系统函数stoi来实现string到int的转换
				//res.push(stoi(tokens[i]));
				res.push(s2int(tokens[i]));
			}
		}
		return res.top();
	}

	inline	int calculate(int a, int b, string ope)
	{
		if (ope == "+")return a + b;
		if (ope == "-")return a - b;
		if (ope == "*")return a * b;
		if (ope == "/")return a / b;
		return 0;
	}

	inline	bool isOperator(string s)
	{
		if (s == "+" || s == "-" || s == "*" || s == "/")return true;
		return false;
	}

	inline int s2int(string s)
	{
		int len = s.length();
		int res = 0;

		int i = 0, sign = 1;
		if (s[i] == '-' || s[i] == '+')
		{
			if (s[i] == '-')sign = -1;
			++i;
		}

		for (; i < len; ++i)
		{
			res *= 10;
			res += s[i] - '0';
		}
		return res * sign;
	}
};

int main()
{
	Solution so;

	string s[] = { "3", "-4", "+" };
	vector<string> tokens(s, s + 3);

	cout << so.evalRPN(tokens) << endl;
	return 0;
}
