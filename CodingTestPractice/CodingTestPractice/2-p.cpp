#include <bits/stdc++.h>
using namespace std;

#pragma region 14502 : 연구소

/*
1. 벽 3개 세우기
2. 바이러스 퍼짐
3. 안전영역 count -> max

범위를 보고 시간복잡도 고려
효율적인 벽세우기x -> 무식하게 생각 -> 벽세우기 모든 경우의 수

*/

int arr[10][10];
int visited[10][10]; // 방문표시(바이러스 퍼진곳)
int n, m, result;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
vector<pair<int, int>> wallVec; // 벽을 세우는 지점은 한정되어있으므로 따로 관리
vector<pair<int, int>> virustVec;

void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		// 배열범위이내, 중복방문, 벽인지 확인
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

	// 빈공간 세기
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 빈공간이면서 방문하지않은곳
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

	// 조합(3중for문)
	for (int i = 0; i < wallVec.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < j; k++)
			{
				// 벽세우기
				arr[wallVec[i].first][wallVec[i].second] = 1;
				arr[wallVec[j].first][wallVec[j].second] = 1;
				arr[wallVec[k].first][wallVec[k].second] = 1;
				
				// 최대값 비교하기
				result = max(counting(), result);

				// 원복하기
				arr[wallVec[i].first][wallVec[i].second] = 0;
				arr[wallVec[j].first][wallVec[j].second] = 0;
				arr[wallVec[k].first][wallVec[k].second] = 0;
			}
		}
	}

	cout << result;
}

#pragma endregion
