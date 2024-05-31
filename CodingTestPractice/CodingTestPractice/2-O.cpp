#pragma region 4949 : ±ÕÇüÀâÈù ¼¼»ó

#include <bits/stdc++.h>
using namespace std;

string str;
int main()
{
	while (true)
	{
		bool isEmpty = false;
		getline(cin, str);
		if (str[0] == '.')
			break;

		stack<char> stk;
		for (char c : str)
		{
			if (c == '(' || c == '[')
				stk.push(c);
			else if (c == ')')
			{
				if (stk.empty())
				{
					isEmpty = true;
					break;
				}
				else
				{
					if (stk.top() == '(')
						stk.pop();
					else if (stk.top() == '[')
					{
						isEmpty = true;
						break;
					}
				}
			}
			else if (c == ']')
			{
				if (stk.empty())
				{
					isEmpty = true;
					break;
				}
				else
				{
					if (stk.top() == '[')
						stk.pop();
					else if (stk.top() == '(')
					{
						isEmpty = true;
						break;
					}
				}
			}
		}

		if (stk.empty() && !isEmpty)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}

#pragma endregion
