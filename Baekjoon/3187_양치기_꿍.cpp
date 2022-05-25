#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int da[4] = {-1, 0, 0, 1};
const int db[4] = {0, -1, 1, 0};

typedef struct pos{
    int a,b;
}Pos;

int r,c;
char ar[251][251];
bool vis[251][251]={false,};

bool Condition(int a,int b)
{
    if (a<0 || b<0 || a>=r || b>=c)
        return false;
    if (vis[a][b] || ar[a][b] == '#')
        return false;
    
    return true;
}

void bfs()
{
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (!vis[i][j] && ar[i][j] != '#')
            {
                queue<Pos> q;
                vector<Pos> wolves;
                vector<Pos> lambs;
                q.push({i,j});
                vis[i][j] = true;
                if (ar[i][j] == 'v'){
                    wolves.push_back({i,j});
                }
                else if (ar[i][j] == 'k'){
                    lambs.push_back({i,j});
                }

                while (!q.empty())
                {
                    int currA = q.front().a;
                    int currB = q.front().b;
                    q.pop();

                    for (int k=0; k<4; k++){
                        int nextA = currA + da[k];
                        int nextB = currB + db[k];

                        if (Condition(nextA,nextB))
                        {
                            if (ar[nextA][nextB] == 'v'){
                                wolves.push_back({nextA,nextB});
                            }
                            else if (ar[nextA][nextB] == 'k'){
                                lambs.push_back({nextA,nextB});
                            }

                            q.push({nextA,nextB});
                            vis[nextA][nextB] = true;
                        }
                    }
                }

                if (lambs.size() > wolves.size()){
                    for (int k=0; k<wolves.size(); k++){
                        ar[wolves[k].a][wolves[k].b] = '.';
                    }
                }
                else {
                    for (int k=0; k<lambs.size(); k++){
                        ar[lambs[k].a][lambs[k].b] = '.';
                    }
                }
            }
        }
    }
}

Pos checkAnimals()
{
    int lambCnt = 0, wolfCnt = 0;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (ar[i][j] == 'v') wolfCnt++;
            else if (ar[i][j] == 'k') lambCnt++;
        }
    }

    return {lambCnt,wolfCnt};
}

void debug()
{
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cout << ar[i][j];
        }
        cout << '\n';
    }
}

int main()
{
    cin >> r >> c;

    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cin >> ar[i][j];
        }
    }

    bfs();
    Pos ans = checkAnimals();
    //debug();
    cout << ans.a << ' ' << ans.b << '\n';

    return 0;
}
