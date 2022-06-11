#include <iostream>
#include <vector>
using namespace std;

typedef struct node{
    vector<int> par;
    vector<int> son;
}Node;

vector<Node> v(101);
int t1,t2;
int ans = -1;
bool vis[101] = {false,};

void dfs(int n, int cnt)
{
    vis[n] = true;

    if (n == t2){
        ans = cnt;
        return;
    }

    for (int i=0; i<v[n].par.size(); i++)
    {
        if (vis[v[n].par[i]]) continue;
        dfs(v[n].par[i],cnt+1);
    }

    for (int i=0; i<v[n].son.size(); i++)
    {
        if (vis[v[n].son[i]]) continue;
        dfs(v[n].son[i],cnt+1);
    }
}

int main()
{
    int n,m;
    cin >> n >> t1 >> t2 >> m;

    for (int i=0; i<m; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        v[tmp1].son.push_back(tmp2);
        v[tmp2].par.push_back(tmp1);
    }

    dfs(t1,0);
    cout << ans << '\n';
    
    return 0;
}
