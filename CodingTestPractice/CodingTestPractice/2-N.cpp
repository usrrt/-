#pragma region 9012 : ��ȣ
#include <bits/stdc++.h>
using namespace std;

/*
¦����, ����, �Ƹ��ٿ� ��ȣ -> stack�� �̿��� ����
'('�� stack�� �װ� ')'�� ������ pop
���� stack�� ������̶�� yes, �ƴ϶�� no
��������� ')'�� �ԷµǸ� ������� �����Ƿ� no
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