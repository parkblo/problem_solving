#include <iostream>
using namespace std;

int main()
{
	int dp[2][41];
	dp[0][0]=1; dp[0][1]=0;
	dp[1][0]=0; dp[1][1]=1;

	int t;
	cin >> t;

	for (int i=2; i<=40; i++)
	{
		dp[0][i] = dp[0][i-1] + dp[0][i-2];
		dp[1][i] = dp[1][i-1] + dp[1][i-2];
	}

	for (int i=0; i<t; i++)
	{
		int n;
		cin >> n;

		cout << dp[0][n] << ' ' << dp[1][n] << '\n';
	}

	return 0;
}
