#include <bits/stdc++.h>
using namespace std;

#pragma region 1325 : 효율적인 해킹

/*
모든 정점을 탐색한다는 가정시 i = 0 -> n dfs(i)일때 최악의 조건을 고려하면 시간복잡도는 n^2이 된다
n은 1만이므로 1억의 시간복잡도 -> 시간초과
*/

int n, m, a, b;
vector<vector<int>> adj;
vector<int> visited;
vector<int> com;

int dfs(int h)
{
	visited[h] = 1;
	int result = 1;
	for (int t : adj[h])
	{
		if (visited[t] == 1)
			continue;

		visited[t] = 1;
		result += dfs(t);
	}
	return result;
}

int main()
{
	cin >> n >> m;
	adj.resize(n + 1);
	visited.resize(n + 1);
	com.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		adj[b].push_back(a); // a가 b를 신뢰 -> b와 연관된 a를 알아야하므로 adj[b]에 a를 push한다
	}
	
	// 모든 정점확인 필요
	int mx = 0;
	for (int i = 1; i <= n; i++)
	{
		fill(visited.begin(), visited.end(), 0); // 테스트케이스 마다 초기화
		com[i] = dfs(i);
		mx = max(mx, com[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		if (mx == com[i])
			cout << i << ' ';
	}
}

#pragma endregion

