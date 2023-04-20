#include <iostream>                                                            
#include <vector>
#include <queue>
using namespace std;
const int MAX = 1001;

vector<int> adj[MAX];
int indegree[MAX];
queue<int> q;
int result[MAX];
 
int main() {
    int N, M;
    cin >> N >> M;
 
    int a, b;
    for (int i=0; i<M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
 
    for (int i=1; i<=N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
        result[i] = 1;
    }
 
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
 
        for (int i=0; i<adj[cur].size(); i++) {
            int next = adj[cur][i];
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
                result[next] = max(result[next], result[cur]+1); //★
            }
        }
    }
 
    for (int i=1; i<=N; i++) {
        cout << result[i] << " ";
    }
 
    return 0;
}
