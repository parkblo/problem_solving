#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    int time[501];
    int indegree[501]={0};
    int result[501]={0};
    vector<int> adj[501];
    queue<int> q;

    cin >> N;

    for (int i=1; i<=N; i++)
    {
        int tmp;
        cin >> tmp;
        time[i] = tmp;
        while (1)
        {
            cin >> tmp;
            if (tmp == -1) break;

            indegree[i]++;
            adj[tmp].push_back(i);
        }
    }

    for (int i=1; i<=N; i++){
        if (indegree[i] == 0) {
            result[i] = time[i];
            q.push(i);
        }
    }

    for (int i=1; i<=N; i++){
        if (q.empty()){
            puts("0");
            return 0;
        }

        int curr = q.front();
        q.pop();

        for (int next: adj[curr]){
            result[next] = max(result[next],result[curr]+time[next]);
            if (--indegree[next] == 0) q.push(next);
        }
    }

    for (int i=1; i<=N; i++){
        cout << result[i] << '\n';
    }

    return 0;
}
