#include <iostream>
#include <queue>
using namespace std;

const int da[4] = {-1,1,0,0};
const int db[4] = {0,0,-1,1};

typedef struct position{
    int a,b;
}Pos;

bool Condition(bool vis[][101], int n, int a, int b)
{
    if (a<0 || b<0 || a>=n || b>=n)
        return false;
    if (vis[a][b])
        return false;
    
    return true;
}

int BFS(char ar[][101], int n)
{
    bool vis[101][101] = {false,};
    int cnt=0;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (Condition(vis,n,i,j)){
                cnt++;
                queue<Pos> q;
                q.push({i,j});
                vis[i][j] = true;

                while(!q.empty())
                {
                    int currA = q.front().a;
                    int currB = q.front().b;
                    q.pop();

                    for (int k=0; k<4; k++){
                        int nextA = currA + da[k];
                        int nextB = currB + db[k];

                        if (Condition(vis,n,nextA,nextB)
                        && ar[currA][currB] == ar[nextA][nextB])
                        {
                            q.push({nextA,nextB});
                            vis[nextA][nextB] = true;
                        }
                    }
                }
            }
        }
    }

    return cnt;
}

int main()
{
    char ar[101][101];
    int n;

    cin >> n;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> ar[i][j];
        }
    }

    cout << BFS(ar,n) << ' ';

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (ar[i][j] == 'R')
                ar[i][j] = 'G';
        }
    }

    cout << BFS(ar,n) << '\n';

    return 0;
}
