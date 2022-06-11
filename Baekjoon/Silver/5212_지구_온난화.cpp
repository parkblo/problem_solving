#include <iostream>
#include <algorithm>
using namespace std;

const int da[4] = {-1,0,0,1};
const int db[4] = {0,-1,1,0};

int ar[11][11];
int pr[11][11];
int r,c;

bool Condition(int a, int b)
{
    if (a<0 || b<0 || a>=r || b>=c)
        return false;
    
    return true;
}

bool isCollapse(int a, int b)
{
    int cnt=0;
    for (int i=0; i<4; i++)
    {
        int nextA = a + da[i];
        int nextB = b + db[i];

        if (!Condition(nextA,nextB) || ar[nextA][nextB] == 0)
        {
            cnt++;
        }
    }

    if (cnt>=3)
        return true;
    return false;
}

int main()
{
    char ctmp;

    cin >> r >> c;

    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cin >> ctmp;
            if (ctmp == '.'){
                ar[i][j] = 0;
                pr[i][j] = 0;
            }
            else {
                ar[i][j] = 1;
                pr[i][j] = 1;
            }
        }
    }

    // 50 years after...

    int firstI = 100, lastI = 0, firstJ = 100, lastJ = 0;

    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (ar[i][j] == 1 && isCollapse(i,j)){
                pr[i][j] = 0;
            }

            if (pr[i][j] == 1){
                firstI = min(firstI,i); lastI = max(lastI,i);
                firstJ = min(firstJ,j); lastJ = max(lastJ,j);
            }
        }
    }

    for (int i=firstI; i<=lastI; i++){
        for (int j=firstJ; j<=lastJ; j++){
            if (pr[i][j] == 0) cout << '.';
            else cout << 'X';
        }
        cout << '\n';
    }

    return 0;
}
