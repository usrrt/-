#pragma region 9012 : 괄호
#include <bits/stdc++.h>
using namespace std;

/*
짝짓기, 폭발, 아름다운 괄호 -> stack을 이용한 문제
'('을 stack에 쌓고 ')'을 만나면 pop
최종 stack이 빈공간이라면 yes, 아니라면 no
비어있을때 ')'가 입력되면 사라지지 않으므로 no
*/
int t;
string str;

bool vps(string str)
{
	stack<char> stk;
	for (char ch : str)
	{
		if (ch == '(')
			stk.push(ch);
		else
		{
			if (!stk.empty())
				stk.pop();
			else
				return false;
		}
	}

	if (stk.empty())
		return true;
	else
		return false;
}

int main()
{
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> str;
		if (vps(str))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
#pragma endregion