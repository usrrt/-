#include <bits/stdc++.h>
using namespace std;

#pragma region 11655 : ROT13

string s;
string Rot13(string str)
{
	string ret;
	for (char c : str)
	{
		if (c >= 'a' && c <= 'z')
		{
			if (c + 13 > 'z')
				c -= 13;
			else
				c += 13;
		}
		else if (c >= 'A' && c <= 'Z')
		{
			if (c + 13 > 'Z')
				c -= 13;
			else
				c += 13;
		}
		ret.push_back(c);
	}

	return ret;
}

int main()
{
	getline(cin, s);
	s = Rot13(s);
	cout << s;
}

#pragma endregion
