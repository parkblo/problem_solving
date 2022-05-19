#include <iostream>
#include <algorithm>
using namespace std;

int m,n;
int snack[1000001];

bool f(int mid)
{
    int cnt=0;

    for (int i=0; i<n; i++)
    {
        cnt += snack[i]/mid;
    }

    if (cnt >= m) return true;
    return false;
}

int main()
{
    int maxS=0, minS=1000000001;

    cin >> m >> n;

    for (int i=0; i<n; i++){
        cin >> snack[i];
        maxS = max(snack[i],maxS);
    }

    int left = 1, right = maxS, ret=0;

    while (left <= right)
    {
        int mid = (left+right)/2;

        if (f(mid))
        {
            left = mid + 1;
            ret = mid;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << ret << '\n';
    return 0;
}
