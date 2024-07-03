#include<bits/stdc++.h>
using namespace std;

#pragma region 10988 : 팰린드롬인지 확인하기

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
}

#pragma endregion
