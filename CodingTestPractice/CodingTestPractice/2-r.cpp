#include <bits/stdc++.h>
using namespace std;

#pragma region 1068 : 트리

/*
- 트리는 root 노드부터 탐색
- leaf노드는 자식노드가 없는것

노드를 지운다
	- 1. 진짜 지운다
	- 2. 해당부분을 탐색하지 않는다
*/

int n, parent, delNodeNum, root;
vector<int> adj[51]; // 인접리스트로 트리 표현
set<int> delNodes;

// leaf노드 수를 구하는 함수
int dfs(int here)
{
	// 현재 노드의 삭제 여부 확인
	if (delNodes.count(here))
		return 0;

	int child = 0;
	int leafCnt = 0;
	for (int there : adj[here])
	{
		// 자식노드중 삭제되지 않은 노드들만 탐색
		if(!delNodes.count(there))
		{
			leafCnt += dfs(there);
			child++;
		}
	}

	if (child == 0)
		return 1;

	return leafCnt;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) // i 는 node 번호
	{
		cin >> parent;
		if (parent == -1)
		{
			root = i;
		}
		else
		{
			adj[parent].push_back(i);
		}
	}

	cin >> delNodeNum;
	delNodes.insert(delNodeNum);

	cout << dfs(root);
}

#pragma endregion