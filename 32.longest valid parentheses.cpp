/******************************************
problem:
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

author: guohongzhi

language: C / C++
******************************************/

/*c++*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int len = s.length();
		stack<int> st;
		int mx = 0, last = -1;

		for (int i = 0; i < len; ++i)
		{
			if (s[i] == '(')st.push(i);
			else
			{
				if (!st.empty())
				{
					st.pop();
					if (st.empty())
					{
						mx = maxx(mx, i - last);
					}
					else
					{
						mx = maxx(mx, i - st.top());
					}
				}
				else
				{
					last = i;
				}
			}
		}
		return mx;
	}

	int maxx(int a, int b)
	{
		if (a > b)return a;
		return b;
	}
};

int main()
{
	string s = "()())()()()()";
	Solution so;
	cout << so.longestValidParentheses(s) << endl;
	return 0;
}
