#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 32001

int main()
{
	int N, M, indegree[MAX];
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> ans;
	vector<int> adj[MAX];

	cin >> N >> M;
	for (int i=0; i<M; i++){
		int A, B;
		cin >> A >> B;
		indegree[B]++;
		adj[A].push_back(B);
	}

	for (int i=1; i<=N; i++){
		if (indegree[i] == 0) pq.push(i);
	}

	for (int i=1; i<=N; i++){
		int curr = pq.top();
		pq.pop();
		ans.push_back(curr);

		for (int next: adj[curr]){
			if (--indegree[next] == 0) pq.push(next);
		}
	}

	for (int i=0; i<ans.size(); i++){
		cout << ans[i] << ' ';
	}

	return 0;
}
