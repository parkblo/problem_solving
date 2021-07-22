#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

#define MAX 9
int N,M;
int arr[MAX] = {0,};

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
		arr[cnt] = i;
		dfs(cnt+1);
	}
}

int main()
{
	cin >> N >> M;
	dfs(0);
	return 0;
}
