#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> que;
bool visited[1001] = {false,};
bool visitedBfs[1001] = {false, };

void DFS(int curr)
{
  visited[curr] = true;
  cout << curr << ' ';

  for (int i=0; i<adj[curr].size(); i++)
  {
    int next = adj[curr][i];
    if (visited[next] == true) continue;
    DFS(next);
  }
}

int main()
{
  int a, b, v, N, M;
	cin >> N >> M >> v;
	adj.resize(N+1);
  for (int i=0; i<M; i++)
  {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  // 정점 번호가 작은 것을 먼저 방문
  for (int i=1; i<=N; i++)
    sort(adj[i].begin(), adj[i].end());

  // DFS
  DFS(v); cout << endl;

  // BFS
  que.push_back(v); visitedBfs[v] = true;
  while (!que.empty())
  {
    int head = que[0];
    cout << head << ' ';
    for (int i=0; i<adj[head].size(); i++)
    {
      int next = adj[head][i];
      if (visitedBfs[next] == true) continue;
      que.push_back(next);
      visitedBfs[next] = true;
    }
    que.erase(que.begin());
  }
}
