#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int da[4]={-1,0,0,1};
const int db[4]={0,1,-1,0};

typedef struct position{
    int a,b;
}Pos;

int n;
int highest=0, ans=1;
int ar[101][101];

bool Condition(int a, int b, int s, bool vis[][101])
{
    if (a<0 || b<0 || a>=n || b>=n)
        return false;
    if (vis[a][b] || ar[a][b] <= s)
        return false;
    
    return true;
}

void bfs(int standard) //standard 이하는 물에 잠깁니다.
{
    bool vis[101][101]={false,};
    queue<Pos> q;
    int cnt=0;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (Condition(i,j,standard,vis)){
                cnt++;
                vis[i][j] = true;
                q.push({i,j});

                while (!q.empty())
                {
                    int currA = q.front().a;
                    int currB = q.front().b;
                    q.pop();

                    for (int k=0; k<4; k++){
                        int nextA = currA + da[k];
                        int nextB = currB + db[k];
                        if (Condition(nextA,nextB,standard,vis)){
                            q.push({nextA,nextB});
                            vis[nextA][nextB] = true;
                        }
                    }
                }
            }
        }
    }

    ans = max(ans,cnt);
    return;
}

int main()
{
    cin >> n;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> ar[i][j];
            highest = max(highest,ar[i][j]);
        }
    }

    for (int i=1; i<highest; i++){
        bfs(i);
    }

    cout << ans << '\n';
    return 0;
}
