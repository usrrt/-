#pragma region 17298 : ��ū��

#include <bits/stdc++.h>
using namespace std;

/*
¦���� : �ϴ� ������ �����غ���. �׷��� �������� ��� ����? �ٵ� �� ���� ���� ���� ���ø� �־�� �ȵ� �Ͱ���. ��? 3 2 1 4 ���� ���� 3 2 1�� ��ū���� 4�� �Ǿ�� �ϱ� ������ �ܼ��� 1 - 4 ���� ¦����� �ȵǰڳ� ���� -> �迭�� ��������.
�� �迭�ϱ�? : 3 2 1 �� 4��� ���� ��ƾ� �ڴٰ� ����.
������ ��°��� �ϴ� ��´ٰ� ���� (���� ¦���� �������� ���� �׳� �� �ϴ� ���� �� ���迡 ���߾� ����)�׷��ٸ� ������ ��� �ؾ��ұ�?
���ÿ� 3 2 1 �� ��Ƶξ��� �� 4�������� �� 3 2 1�̶�� ������ 4�� �Ҵ�Ǿ�� ��. -> ���������� ���鼭 �ش� ���� ��������� ��.
�� �� push�� ���� �ؾ��ұ�?: pop�� �����ؾ��ұ�? 4�� ������ �� ���°� �����̱� ������ pop -> push�� ������� ���� ����
*/

int n;
vector<int> a;
vector<int> neg;

int main()
{
	cin >> n;
	a.resize(n + 1);
	neg.resize(n + 1);
	fill(neg.begin(), neg.end(), -1);
	stack<int> stk;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		while (!stk.empty())
		{
			int st = a[stk.top()];
			// stk.top = 0, a[f1] > a[0] �϶� neg[0] = a[1], pop
			if (a[stk.top()] < a[i])
			{
				neg[stk.top()] = a[i];
				stk.pop();
			}
			else
				break;
		}
		stk.push(i);
	}

	for (int i = 0; i < n; i++)
	{
		cout << neg[i] << ' ';
	}
}


#pragma endregion
