#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	int dp[100010];
	int coin[110];

	cin >> n >> k;
	for (int i=1; i<=n; i++){
		cin >> coin[i];
	}

	dp[0] = 1;
	for (int i=1; i<=n; i++){
		for (int j = coin[i]; j<=k; j++){
			if (j-coin[i] >= 0){
				dp[j] += dp[j - coin[i]];
			}
		}
	}

	cout << dp[k] << "\n";
	return 0;
}
