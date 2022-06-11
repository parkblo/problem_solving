#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int da[8]={-1,-1,-1,0,0,1,1,1};
const int db[8]={-1,0,1,-1,1,-1,0,1};

int ar[51][51];
int n,m;

typedef struct position{
    int a,b,cnt;
}Pos;

bool Condition(bool vis[][51], int a, int b)
{
	if (a<0 || b<0 || a>=n || b>=m)
        return false;
    if (vis[a][b])
        return false;

    return true;
}

int BFS(int sa, int sb)
{
    queue<Pos> q;
    bool vis[51][51] = {false,};

    q.push({sa,sb,0});
    vis[sa][sb] = true;

    while (!q.empty())
    {
        int currA = q.front().a;
        int currB = q.front().b;
        int currC = q.front().cnt;
        q.pop();

        if (ar[currA][currB] == 1)
        {
            return currC;
        }

        for (int i=0;i<8;i++){
            int nextA = currA + da[i];
            int nextB = currB + db[i];
            int nextC = currC + 1;
            if (Condition(vis,nextA,nextB)){
                q.push({nextA,nextB,nextC});
                vis[nextA][nextB] = true;
            }
        }
    }

    return -1;
}

int main()
{
    int ans=0;
	cin >> n >> m;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> ar[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (ar[i][j] == 0){
                ans = max(ans,BFS(i,j));
            }
        }
    }

	cout << ans << '\n';
	return 0;
}
