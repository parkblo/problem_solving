#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int N,M,K;
    int indegree[100001]={0};
    int built[100001]={0};
    vector<int> adj[100001];

    scanf("%d %d %d",&N,&M,&K);

    for (int i=0; i<M; i++){
        int X, Y;
        scanf("%d %d",&X,&Y);
        indegree[Y]++;
        adj[X].push_back(Y);
    }

    for (int i=0; i<K; i++){
        int CMD,A;
        scanf("%d %d",&CMD,&A);
        
        if (CMD == 1)
        {
            if (indegree[A] <= 0){
                built[A]++;
                if (built[A] == 1){
                    for (int next: adj[A]){
                        indegree[next]--;
                    }
                }
            }
            else {
                cout << "Lier!" << '\n';
                return 0;
            }
        }
        else if (CMD == 2)
        {
            if (built[A] == 0){
                cout << "Lier!" << '\n';
                return 0;
            }
            else{
                built[A]--;
                if (built[A] == 0){
                    for (int next: adj[A]){
                        indegree[next]++;
                    }
                }
            }
        }
    }
    
    cout << "King-God-Emperor" << '\n';
    return 0;
}
