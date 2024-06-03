#include <bits/stdc++.h>
using namespace std;

#pragma region 1068 : Ʈ��

/*
- Ʈ���� root ������ Ž��
- leaf���� �ڽĳ�尡 ���°�

��带 �����
	- 1. ��¥ �����
	- 2. �ش�κ��� Ž������ �ʴ´�
*/

int n, parent, delNodeNum, root;
vector<int> adj[51]; // ��������Ʈ�� Ʈ�� ǥ��
set<int> delNodes;

// leaf��� ���� ���ϴ� �Լ�
int dfs(int here)
{
	// ���� ����� ���� ���� Ȯ��
	if (delNodes.count(here))
		return 0;

	int child = 0;
	int leafCnt = 0;
	for (int there : adj[here])
	{
		// �ڽĳ���� �������� ���� ���鸸 Ž��
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
	for (int i = 0; i < n; i++) // i �� node ��ȣ
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