#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
bool visited[1001] = {false,};
int cnt=0;

void DFS(int curr)
{
	visited[curr] = true;
	
	for (int i=0; i<adj[curr].size(); i++)
	{
		int next = adj[curr][i];
		if (visited[next] == true) continue;
		DFS(next);
	}
}

int main()
{
	int n,m,a,b;
	cin >> n;
	adj.resize(n+1);
	cin >> m;
	
	for (int i=0; i<m; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for (int i=1; i<=n; i++){
		if (visited[i] == false){
			DFS(i);
			cnt++;
		}
	}
	
	cout << cnt;
}
