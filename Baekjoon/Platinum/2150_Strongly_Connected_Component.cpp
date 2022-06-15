#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10001

int V, E, cnt, dfsn[MAX], sn[MAX], SN;
bool finished[MAX] = {false,};
vector<int> adj[MAX];
vector<vector<int>> SCC;
stack<int> S;

int DFS(int curr)
{
    dfsn[curr] = ++cnt;
    S.push(curr);

    int result = dfsn[curr];

    for (int next: adj[curr]){
        if (dfsn[next] == 0) result = min(result, DFS(next));
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
        sort(currSCC.begin(),currSCC.end());
        SCC.push_back(currSCC);
        SN++;
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> V >> E;
    for (int i=0; i<E; i++){
        int a,b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
    }

    for (int i=0; i<V; i++){
        if(dfsn[i] == 0) DFS(i);
    }

    sort(SCC.begin(), SCC.end());

    cout << SN << '\n';
    for (auto& currSCC: SCC){
        for(int curr: currSCC){
            cout << curr+1 << ' ';
        }
        cout << "-1\n";
    }
    
    return 0;
}
