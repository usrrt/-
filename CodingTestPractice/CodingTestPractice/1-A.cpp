#include <bits/stdc++.h>
using namespace std;

#pragma region 2309 : 일곱난쟁이
// 순열
//vector<int> a;
//int main()
//{
//	int input = 0;
//	for (int i = 0; i < 9; i++)
//	{
//		cin >> input;
//		a.push_back(input);
//	}
//	sort(a.begin(), a.end());
//	do
//	{
//		int sum = 0;
//
//		for (int i = 0; i < 7; i++)
//		{
//			sum += a[i];
//		}
//		if (sum == 100)
//			break;
//	} while (next_permutation(a.begin(), a.end()));
//
//	for (int i = 0; i < 7; i++)
//	{
//		cout << a[i] << '\n';
//	}
//}

// 조합 : 9개중 아닌 2개 고르기
//int a[9];
//int sum;
//pair<int, int> x;
//void combi()
//{
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (sum - a[i] - a[j] == 100)
//			{
//				x = { i, j };
//				return;
//			}
//		}
//	}
//}
//
//int main()
//{
//	for (int i = 0; i < 9; i++)
//	{
//		cin >> a[i];
//		sum += a[i];
//	}
//	combi();
//	vector<int> v;
//	for (int i = 0; i < 9; i++)
//	{
//		if (i == x.first || i == x.second)
//			continue;
//		//cout << a[i] << '\n';
//		v.push_back(a[i]);
//	}
//	sort(v.begin(), v.end());
//	for (int i : v)
//		cout << i << '\n';
//}

// 재귀로 구현한 순열
int a[9];
void makePermutation(int n, int r, int depth)
{
	if (r == depth)
	{
		int sum = 0;
		for (int i = 0; i < r; i++)
			sum += a[i];
		
		if (sum == 100)
		{
			for (int i = 0; i < 7; i++)
				cout << a[i] << '\n';
			
			exit(0);
		}

		return;
	}

	for (int i = depth; i < n; i++)
	{
		swap(a[i], a[depth]);
		makePermutation(n, r, depth + 1);
		swap(a[i], a[depth]);
	}

	return;
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
	}
	sort(a, a + 9);
	makePermutation(9, 7, 0);
}

#pragma endregion
