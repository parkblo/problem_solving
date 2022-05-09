#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, dp[10001], ar[10001];
	cin >> n;

	for (int i=1; i<=n; i++)
		cin >> ar[i];

	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<=i-1; j++)
		{
			if (dp[i] == 0) dp[i] = dp[j] + ar[i-j];
			else dp[i] = min(dp[i],dp[j] + ar[i-j]);
		}
	}

	cout << dp[n];
	return 0;
}
