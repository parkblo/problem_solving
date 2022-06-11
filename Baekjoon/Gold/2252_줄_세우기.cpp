#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 32001

int main()
{
    int N,M;
    int indegree[MAX]={0};
    int ans[MAX];
    vector<int> adj[MAX];
    queue<int> q;

    cin >> N >> M;

    while (M--)
    {
        int prev, next;
        cin >> prev >> next;
        indegree[next]++;
        adj[prev].push_back(next);
    }

    for (int i=1; i<=N; i++){
        if (indegree[i] == 0)
            q.push(i);
    }

    for (int i=1; i<=N; i++)
    {
		if(q.empty()){
			puts("0");
			return 0;
		}
		
        int curr = q.front();
        q.pop();
        ans[i] = curr;

        for (int next: adj[curr])
        {
            if (--indegree[next] == 0)
                q.push(next);
        }
    }

    for (int i=1; i<=N; i++){
        printf("%d ",ans[i]);
    }
    cout << '\n';
    return 0;
}
