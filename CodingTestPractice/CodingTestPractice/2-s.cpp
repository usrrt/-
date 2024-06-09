#include <bits/stdc++.h>
using namespace std;

#pragma region 1325 : ȿ������ ��ŷ

/*
��� ������ Ž���Ѵٴ� ������ i = 0 -> n dfs(i)�϶� �־��� ������ ����ϸ� �ð����⵵�� n^2�� �ȴ�
n�� 1���̹Ƿ� 1���� �ð����⵵ -> �ð��ʰ�
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
		adj[b].push_back(a); // a�� b�� �ŷ� -> b�� ������ a�� �˾ƾ��ϹǷ� adj[b]�� a�� push�Ѵ�
	}
	
	// ��� ����Ȯ�� �ʿ�
	int mx = 0;
	for (int i = 1; i <= n; i++)
	{
		fill(visited.begin(), visited.end(), 0); // �׽�Ʈ���̽� ���� �ʱ�ȭ
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

