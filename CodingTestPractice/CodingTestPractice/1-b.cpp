#include <bits/stdc++.h>
using namespace std;

#pragma region 10808 : ���ĺ� ����

/*
counting star => ��/�迭

map -> string
arr -> int
	- ��, ���� ���ö� ������ ��ġ�� �Ҵ�Ǵ°� �ƴ� ū ����(10��, 100��)�� �Ҵ�ȴٸ� map ���
*/

string s;
int arr[26];
int main()
{
	cin >> s;
	for (char c : s)
		arr[c - 'a']++;

	for (int i : arr)
		cout << i << ' ';
}

#pragma endregion
