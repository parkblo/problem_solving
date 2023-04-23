#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100

int N, cnt=0, SN, dfsn[MAX], sn[MAX], cost[MAX];
bool finished[MAX];
stack<int> S;
vector<int> adj[MAX];
vector<vector<int>> SCC;

bool cmp(int& a, int& b){
	if (cost[a] < cost[b]) return true;

	return false;
}

int DFS(int curr)
{
	dfsn[curr] = ++cnt;
	S.push(curr);

	int result = dfsn[curr];
	for (int next: adj[curr]){
		if (dfsn[next] == 0) result = min(result,DFS(next));
		else if (!finished[next]) result = min(result, dfsn[next]);
	}

	if (result == dfsn[curr]){
		vector<int> currSCC;
		while (1){
			int t = S.top();
			S.pop();
			currSCC.push_back(t);
			finished[t] = true;
			sn[t] = SN;
			if (t == curr) break;
		}

		sort(currSCC.begin(), currSCC.end(),cmp);
		SCC.push_back(currSCC);
		SN++;
	}
	
	return result;
}

int main()
{
	scanf("%d",&N);

	for (int i=0; i<N; i++){
		scanf("%d",&cost[i]);
	}
	
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			int tmp;
			scanf("%1d",&tmp);
			if (tmp) adj[i].push_back(j);
		}
	}

	for (int i=0; i<N; i++){
		if (dfsn[i] == 0) DFS(i);
	}

	int ans = 0;
	for (auto& currSCC: SCC){
		ans += cost[currSCC[0]];
	}

	printf("%d\n",ans);
	return 0;
}
