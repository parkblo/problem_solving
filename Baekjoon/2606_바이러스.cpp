#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
bool visited[101] = {false,};
int cnt=0;

void DFS(int curr)
{
	visited[curr] = true;
	cnt++;
	
	for (int i=0; i<adj[curr].size(); i++)
	{
		int next = adj[curr][i];
		if (visited[next] == true) continue;
		DFS(next);
	}
}

int main()
{
	int n,t,a,b;
	cin >> n;
	adj.resize(n+1);
	cin >> t;
	
	for (int i=0; i<t; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	DFS(1);
	cout << cnt-1;
}
