#pragma region 17298 : 오큰수

#include <bits/stdc++.h>
using namespace std;

/*
짝짓기 : 일단 스택을 생각해보자. 그러면 스택으로 어떻게 하지? 근데 이 문제 같은 경우는 스택만 있어서는 안될 것같다. 왜? 3 2 1 4 같은 경우는 3 2 1의 오큰수는 4가 되어야 하기 때문에 단순히 1 - 4 같이 짝짓기는 안되겠네 생각 -> 배열을 생각하자.
왜 배열일까? : 3 2 1 에 4라는 값을 담아야 겠다고 생각.
스택을 담는것을 일단 담는다고 생각 (원래 짝짓기 문제에서 보통 그냥 다 일단 담음 그 경험에 비추어 생각)그렇다면 뺄때는 어떻게 해야할까?
스택에 3 2 1 을 담아두었을 때 4가나왔을 때 3 2 1이라는 값에는 4가 할당되어야 함. -> 순차적으로 빼면서 해당 값을 집어넣으면 끝.
이 때 push를 먼저 해야할까?: pop을 먼저해야할까? 4가 나왔을 때 빼는게 먼저이기 때문에 pop -> push를 기반으로 로직 구축
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
			// stk.top = 0, a[f1] > a[0] 일때 neg[0] = a[1], pop
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
