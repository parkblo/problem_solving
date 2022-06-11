#include <iostream>
using namespace std;

int main()
{
	int n,dp[100001];
	cin >> n;
	
	dp[1] = 3;
	dp[2] = 7;
	
	for (int i=3; i<=n; i++){
		dp[i] = (dp[i-1]*2 + dp[i-2])%9901;
	}

	cout << dp[n] << '\n';
	return 0;
}
