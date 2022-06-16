#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 10001

int main()
{
	int ans=0;
	int N,indegree[MAX],time[MAX],d[MAX];
	vector<int> adj[MAX];
	queue<int> Q;
	
	cin >> N;
	for (int i=1; i<=N; i++){
		int T,E;
		cin >> T >> E;
		time[i] = T;
		for (int j=1; j<=E; j++){
			int tmp;
			cin >> tmp;
			indegree[i]++;
			adj[tmp].push_back(i);
		}
	}

	for (int i=1; i<=N; i++){
		if (indegree[i] == 0){
			Q.push(i);
			d[i] = time[i];
		}
	}

	for (int i=1; i<=N; i++){
		int curr = Q.front();
		Q.pop();

		for (int next: adj[curr]){
			d[next] = max(d[next], d[curr] + time[next]);
			if (--indegree[next] == 0) Q.push(next);
		}
	}

	for (int i=1; i<=N; i++){
		ans = max(ans,d[i]);
	}

	cout << ans << '\n';
	return 0;
}
