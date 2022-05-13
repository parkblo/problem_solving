#include <iostream>
#include <queue>
using namespace std;

const int dirA[8] = {-1,-2,-2,-1,1,2,2,1};
const int dirB[8] = {-2,-1,1,2,2,1,-1,-2};

typedef struct position{
    int a,b,cnt;
}POS;

bool isAvailable(int L, int a, int b, bool vis[][301])
{
    if (a<0 || b<0 || a>=L || b>=L)
        return false;
    if (vis[a][b])
        return false;
    return true;
}

int BFS(queue<POS> q, int da, int db, int L)
{
    bool vis[301][301]={false,};
    vis[q.front().a][q.front().b] = true;

    while (!q.empty())
    {
        int currA = q.front().a;
        int currB = q.front().b;
        int currC = q.front().cnt;
        q.pop();

        if (currA == da && currB == db){
            return currC;
        }

        for (int i=0; i<8; i++)
        {
            int nextA = currA + dirA[i];
            int nextB = currB + dirB[i];
            int nextC = currC + 1;
            if (isAvailable(L,nextA,nextB,vis)){
                q.push({nextA,nextB,nextC});
                vis[nextA][nextB] = true;
            }
        }
    }

    return -1;
}

int main()
{
	int T;
	cin >> T;
	
	for (int t=0; t<T; t++)
    {
        queue<POS> q;
        int L,sa,sb,da,db;

        cin >> L >> sa >> sb >> da >> db;
        q.push({sa,sb,0});
        cout << BFS(q,da,db,L) << '\n';
    }

}
