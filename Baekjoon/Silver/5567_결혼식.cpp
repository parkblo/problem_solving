#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v[501];
bool vis[501]= {false,};

void dfs(int target, int cnt)
{
    if (cnt == 2) return;

    for (int i=0; i<v[target].size(); i++)
    {
        vis[v[target][i]] = true;
        dfs(v[target][i], cnt+1);
    }

    return;
}

int main()
{
    int m;

    cin >> n >> m;

    for (int i=0; i<m; i++)
    {
        int i1,i2;
        cin >> i1 >> i2;
        v[i1].push_back(i2);
        v[i2].push_back(i1);
    }

    vis[1] = true;
    dfs(1,0);

    int ans=0;
    for (int i=2; i<=n; i++)
    {
        if(vis[i]) ans++;
    }

    cout << ans << '\n';
    return 0;
}
