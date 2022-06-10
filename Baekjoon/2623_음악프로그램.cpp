#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
 
int main(){
    int N, M, indegree[1000] = {0};
    vector<int> adj[1000];

    scanf("%d %d", &N, &M);

    for(int i=0; i<M; i++)
    {
        int K, prev, curr;
        scanf("%d", &K);
        if(K == 0) continue;
 
        scanf("%d", &prev);
        for(int i=1; i<K; i++)
        {
            scanf("%d", &curr);
            indegree[curr-1]++;
            adj[prev-1].push_back(curr-1);
            prev = curr;
        }
    }
 
    int result[1000];
    queue<int> q;
    for(int i=0; i<N; i++)
        if(indegree[i] == 0) q.push(i);
 
    for(int i=0; i<N; i++){
        if(q.empty()){
            puts("0");
            return 0;
        }
 
        int curr = q.front();
        q.pop();
        result[i] = curr+1;
        for(int next: adj[curr])
            if(--indegree[next] == 0) q.push(next);
    }
 
    for(int i=0; i<N; i++)
        printf("%d\n", result[i]);
    
    return 0;
}
