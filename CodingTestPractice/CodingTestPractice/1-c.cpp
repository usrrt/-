#include<bits/stdc++.h>
using namespace std;

#pragma region 2979 : 트럭주차

int A, B, C;
int s, e;
int t[104];

int main()
{
	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++)
	{
		cin >> s >> e;
		for (int i = s; i < e; i++)
		{
			t[i]++;
		}
	}
	int cost = 0;
	for (int i : t)
	{
		switch (i)
		{
		case 1:
			cost += A;
			break;
		case 2:
			cost += (B * 2);
			break;
		case 3:
			cost += (C * 3);
			break;
		}
	}
	cout << cost;
}

#pragma endregion
