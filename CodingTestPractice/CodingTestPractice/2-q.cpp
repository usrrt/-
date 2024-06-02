#include <bits/stdc++.h>
using namespace std;

#pragma region 2636 : 치즈

/*
판 가장자리에는 치즈가 없다 -> 없는 부분부터 시작해서 치즈를 녹임
	- 만일 가장자리에 치즈가 없다는 설명이 빠져있다면 치즈가 없는 부분을 찾는 로직이 필요함

1. 탐색
2. 0이면 진행, 1이면 저장
3. 저장된 1, 0으로 
4. 시간++

모두 녹기 직전 사이즈 -> 저장된 사이즈

*/

int arr[104][104];
int visited[104][104];
int n, m, melt, cheeze;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
vector<pair<int, int>> v;

void dfs(int y, int x)
{
	visited[y][x] = 1;

	// 치즈좌표 저장 후 탐색 종료
	if (arr[y][x] == 1)
	{
		v.push_back({ y, x });
		return; 
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])
			continue;

		dfs(ny, nx);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	bool isEnd = false;
	while (!isEnd)
	{
		// 초기화
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		v.clear();
		
		// 탐색하면서 치즈인 부분 vector에 저장
		dfs(0, 0);
		cheeze = v.size(); // 저장된 크기 = 치즈 개수

		// 녹은치즈 1 -> 0
		for (auto c : v)
		{
			arr[c.first][c.second] = 0;
		}
		melt++;
		isEnd = true;

		// 순회하면서 치즈가 남았는지 확인 -> 남은치즈가 없으면 반복문 종료
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j])
				{
					isEnd = false;
				}
			}
		}
	}

	cout << melt << '\n' << cheeze;
}

#pragma endregion

