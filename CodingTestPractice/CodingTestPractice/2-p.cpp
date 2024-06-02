#include <bits/stdc++.h>
using namespace std;

#pragma region 14502 : ������

/*
1. �� 3�� �����
2. ���̷��� ����
3. �������� count -> max

������ ���� �ð����⵵ ���
ȿ������ �������x -> �����ϰ� ���� -> ������� ��� ����� ��

*/

int arr[10][10];
int visited[10][10]; // �湮ǥ��(���̷��� ������)
int n, m, result;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
vector<pair<int, int>> wallVec; // ���� ����� ������ �����Ǿ������Ƿ� ���� ����
vector<pair<int, int>> virustVec;

void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		// �迭�����̳�, �ߺ��湮, ������ Ȯ��
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || arr[ny][nx] == 1)
			continue;

		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
	return;
}

int counting()
{
	fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
	for (pair<int, int> v : virustVec)
	{
		visited[v.first][v.second] = 1;
		dfs(v.first, v.second);
	}

	// ����� ����
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// ������̸鼭 �湮����������
			if (arr[i][j] == 0 && !visited[i][j])
				cnt++;
		}
	}

	return cnt;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				virustVec.push_back({ i, j });
			if (arr[i][j] == 0)
				wallVec.push_back({ i, j });
		}
	}

	// ����(3��for��)
	for (int i = 0; i < wallVec.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < j; k++)
			{
				// �������
				arr[wallVec[i].first][wallVec[i].second] = 1;
				arr[wallVec[j].first][wallVec[j].second] = 1;
				arr[wallVec[k].first][wallVec[k].second] = 1;
				
				// �ִ밪 ���ϱ�
				result = max(counting(), result);

				// �����ϱ�
				arr[wallVec[i].first][wallVec[i].second] = 0;
				arr[wallVec[j].first][wallVec[j].second] = 0;
				arr[wallVec[k].first][wallVec[k].second] = 0;
			}
		}
	}

	cout << result;
}

#pragma endregion
