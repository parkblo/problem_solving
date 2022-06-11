#include <iostream>
#include <queue>
using namespace std;

const int da[4] = {-1,0,1,0};
const int db[4] = {0,1,0,-1};

int n,m,r,c,d;
int ar[51][51];

bool Condition(int a, int b)
{
    if (a<0 || b<0 || a>=n || b>=m)
        return false;
    if (ar[a][b] >= 1)
        return false;
    return true;
}

int turn(int a)
{
    if (a == 0) return 3;
    else if (a == 1) return 0;
    else if (a == 2) return 1;
    else if (a == 3) return 2;

    return -1;
}

int main()
{
    cin >> n >> m >> r >> c >> d;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> ar[i][j];
        }
    }

    int currA=r, currB=c, currD=d, ans=0;;
    while (1)
    {
        // 현재 위치를 청소한다.
        if (ar[currA][currB] == 0){
            ar[currA][currB] = 2;
            ans++;
        }

        // 2.a
        bool flag = false;
        for (int i=0; i<4; i++)
        {
            currD = turn(currD);
            int nextA = currA + da[currD];
            int nextB = currB + db[currD];

            if (Condition(nextA, nextB))
            {
                currA = nextA;
                currB = nextB;
                flag = true;
                break;
            }
        }
        // 2.b
        if (!flag)
        {
            int nextA = currA - da[currD];
            int nextB = currB - db[currD];
            if (nextA>=0 && nextB>=0 && nextA<n && nextB<m
            && ar[nextA][nextB] != 1){
                currA = nextA;
                currB = nextB;
            }
            else {
                cout << ans << '\n';
                return 0;
            }
        }
    }
    return 0;
}
