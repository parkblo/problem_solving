#include <iostream>
using namespace std;
#define MOD 10007

int main()
{
	int dp[1001];
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for (int i=3; i<=n ;i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
		dp[i] %= MOD;
	}

	cout << dp[n] << '\n';
	return 0;
}
