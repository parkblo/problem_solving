#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321

int n;
int ans=INF;
int ansIdx=1;
int ar[105][105];
bool vis[105] = {false,};
vector<int> fr[105];

void DFS(int curr, int start, int target, int count)
{
    if (curr == target){
        ar[start][target] = min(ar[start][target],count);
        return;
    }

    for (int i=0; i<fr[curr].size(); i++)
    {
        if (vis[fr[curr][i]]) continue;

        vis[fr[curr][i]] = true;
        DFS(fr[curr][i], start, target, count+1);
        vis[fr[curr][i]] = false;
    }
}

int main()
{
    int m;
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int ta, tb;
        cin >> ta >> tb;
        fr[ta].push_back(tb);
        fr[tb].push_back(ta);
    }

    for (int i=1; i<105; i++){
        for (int j=1; j<105; j++){
            ar[i][j] = INF;
        }
    }

    for (int i=1; i<=n; i++)
    {
        int kebin = 0;

        for (int j=1; j<=n; j++){
            if (i==j) continue;
            DFS(i,i,j,0);
            kebin += ar[i][j];
        }

        if (kebin < ans){
            ans = kebin;
            ansIdx = i;
        }
    }

    cout << ansIdx << '\n';
    return 0;
}
