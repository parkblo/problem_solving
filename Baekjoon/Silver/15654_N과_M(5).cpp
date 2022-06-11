#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 10010
int N,M;
int arr[MAX] = {0,};
bool visited[MAX] = {0,};
priority_queue<int, vector<int>, greater<int> > pq;
vector<int> vec;

void dfs(int cnt)
{
	if(cnt == M)
	{
		for (int i=0;i<M;i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i=1;i<=N;i++)
	{
		if (!visited[i-1])
		{
			visited[i-1] = true;
			arr[cnt] = vec[i];
			dfs(cnt+1);
			visited[i-1] = false;
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i=1; i<=N; i++)
	{
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	vec.push_back(-1);
	for (int i=0; i<N; i++)
	{
		int tmp;
		tmp = pq.top();
		vec.push_back(tmp);
		pq.pop();
	}
	dfs(0);
	return 0;
}
