#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,k;
    int ar[101],dp[100001];

    cin >> n >> k;

    for (int i=1; i<=n; i++)
        cin >> ar[i];
    
    for (int i=1; i<=k; i++)
        dp[i] = 987654321;

    for (int i=1; i<=n; i++)
        dp[ar[i]] = 1;

    for (int i=1; i<=k; i++){
        for (int j=1; j<=n; j++){
            if (i-ar[j] > 0){
                dp[i] = min(dp[i], dp[i-ar[j]] + 1);
            }
        }
    }

	/*
    for (int i=1; i<=k; i++)
    {
        cout << "i:" << i << ' ' << dp[i] << '\n';
    }
	*/

    if (dp[k] == 987654321) cout << "-1" << '\n';
    else cout << dp[k] << '\n';

    return 0;
}
