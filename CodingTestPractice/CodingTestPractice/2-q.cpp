#include <bits/stdc++.h>
using namespace std;

#pragma region 2636 : ġ��

/*
�� �����ڸ����� ġ� ���� -> ���� �κк��� �����ؼ� ġ� ����
	- ���� �����ڸ��� ġ� ���ٴ� ������ �����ִٸ� ġ� ���� �κ��� ã�� ������ �ʿ���

1. Ž��
2. 0�̸� ����, 1�̸� ����
3. ����� 1, 0���� 
4. �ð�++

��� ��� ���� ������ -> ����� ������

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

	// ġ����ǥ ���� �� Ž�� ����
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
		// �ʱ�ȭ
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		v.clear();
		
		// Ž���ϸ鼭 ġ���� �κ� vector�� ����
		dfs(0, 0);
		cheeze = v.size(); // ����� ũ�� = ġ�� ����

		// ����ġ�� 1 -> 0
		for (auto c : v)
		{
			arr[c.first][c.second] = 0;
		}
		melt++;
		isEnd = true;

		// ��ȸ�ϸ鼭 ġ� ���Ҵ��� Ȯ�� -> ����ġ� ������ �ݺ��� ����
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

