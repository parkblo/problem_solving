#include <iostream>
#include <queue>
using namespace std;

typedef struct position{
    int a,b;
}pos;

bool isAvailable(int a, int b,int da, int db)
{
    if (a<=0 || a>da || b<=0 || b>db)
        return false;
    
    return true;
}

int BFS(int sa, int sb, int da, int db)
{
    queue<pos> q;
    q.push({sa,sb});
    int ret = 0;

    while (!q.empty())
    {
        int currA = q.front().a;
        int currB = q.front().b;
        q.pop();

        if (da == currA && db == currB)
            ret++;

        if (isAvailable(currA+1,currB,da,db)){
            q.push({currA+1,currB});
        }

        if (isAvailable(currA,currB+1,da,db)){
            q.push({currA,currB+1});
        }
    }

    return ret;
}

int main()
{
    int n,m,k;
    int ar[16][16];
    queue<pos> q;

    cin >> n >> m >> k;

    // 받은 수 k를 좌표로 변환
    int tmp = 0;
    int ka=0, kb=0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            tmp++;
            if (tmp == k){
                ka = i;
                kb = j;
            }
        }
    }

    if (k == 0)
        cout << BFS(1,1,n,m);
    else{
        int firstWay = BFS(1,1,ka,kb);
        int secondWay = BFS(ka,kb,n,m);
        cout << firstWay*secondWay << '\n';
    }
    return 0;
}
