#include <iostream>
#include <vector>
using namespace std;

int N;
bool visited[100001]={false,};
int parent[100001];
vector<int> tree[100001];

void DFS(int curr)
{
	visited[curr] = true;

	for (int i=0; i<tree[curr].size(); i++)
	{
		int next = tree[curr][i];

		if (visited[next] == false)
		{
			parent[next] = curr;
			DFS(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i=0; i<N-1; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;

		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}

	DFS(1);

	for (int i=2; i<=N; i++)
		cout << parent[i] << '\n';
	
	return 0;
}
