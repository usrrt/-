#include<bits/stdc++.h>
using namespace std;

#pragma region 10988 : �Ӹ�������� Ȯ���ϱ�

string s;

int main()
{
	cin >> s;
	int result = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] - s[s.size() - 1 - i])
		{
			result = 0;
			break;
		}
	}

	cout << result;

	/*
	string temp = s;
	reverse(s.begin(), s.end());
	temp�� s ��
	*/
}

#pragma endregion
