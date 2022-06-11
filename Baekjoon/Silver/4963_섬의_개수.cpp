#include <iostream>
#include <queue>
using namespace std;

const int da[8] = {-1,1,-1,1,-1,1,0,0};
const int db[8] = {-1,1,1,-1,0,0,-1,1};
int w, h;

typedef struct position{
    int a,b;
}Pos;

bool Condition(int ar[][101], bool vis[][101], int a, int b)
{
    if (a<0 || b<0 || a>=h || b>=w)
        return false;
    if (vis[a][b])
        return false;
    if (ar[a][b] != 1)
        return false;
    
    return true;
}

int BFS(int ar[][101])
{
    bool vis[101][101] = {false,};
    int cnt=0;

    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            if (Condition(ar,vis,i,j)){
                cnt++;
                queue<Pos> q;
                q.push({i,j});
                vis[i][j] = true;

                while(!q.empty())
                {
                    int currA = q.front().a;
                    int currB = q.front().b;
                    q.pop();

                    for (int k=0; k<8; k++){
                        int nextA = currA + da[k];
                        int nextB = currB + db[k];

                        if (Condition(ar,vis,nextA,nextB))
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
    while (1){
        cin >> w >> h;
        int ar[101][101];

        if (w==0 && h==0) break;

        for (int i=0; i<h; i++){
            for (int j=0; j<w; j++){
                cin >> ar[i][j];
            }
        }
        cout << BFS(ar) << '\n';
    }

    return 0;
}
