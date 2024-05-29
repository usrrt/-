#include <bits/stdc++.h>
using namespace std;

#pragma region 1436 : ¿µÈ­°¨µ¶ ¼ò
int t;

int main()
{
	int i = 666;
	cin >> t;
	for (;t > 0; i++)
	{
		if (to_string(i).find("666") != string::npos)
			t--;
	}

	cout << i - 1;
}

#pragma endregion

