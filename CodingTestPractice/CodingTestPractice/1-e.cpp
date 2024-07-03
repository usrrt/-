#include<bits/stdc++.h>
using namespace std;

#pragma region 1159 : ³ó±¸°æ±â
int N;
int cnt[26];
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		cnt[str[0] - 'a']++;
	}
	vector<char> vec;
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] >= 5)
			vec.push_back('a' + i);
	}
	if (!vec.empty())
	{
		sort(vec.begin(), vec.end());
		for (char c : vec)
			cout << c;
	}
	else
		cout << "PREDAJA";
}

#pragma endregion
