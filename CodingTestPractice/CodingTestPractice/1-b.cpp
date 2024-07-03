#include <bits/stdc++.h>
using namespace std;

#pragma region 10808 : 알파벳 개수

/*
counting star => 맵/배열

map -> string
arr -> int
	- 단, 값이 들어올때 인접한 위치에 할당되는게 아닌 큰 범위(10만, 100만)로 할당된다면 map 사용
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
