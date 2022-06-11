#include <iostream>
#include <algorithm>
using namespace std;

int ar[10010];
int dp[10010];
int n;
int ret=0;

int main()
{

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> ar[i];
	
	dp[1] = ar[1];
	dp[2] = ar[1] + ar[2];
	dp[3] = max(ar[1]+ar[3], ar[2]+ar[3]);
	
	for (int i=4; i<=n; i++)
	{
		dp[i] = dp[i-2]+ar[i];

		for (int j=i-3; j>=i-5 && j>=1; j--)
			dp[i] = max(dp[i], ar[i]+ar[i-1]+dp[j]);

		ret = max(dp[i],ret);
	}

	if (n == 1)
		cout << dp[1] << '\n';
	else if (n == 2)
		cout << dp[2] << '\n';
	else if (n == 3)
		cout << max(dp[2],dp[3]) << '\n';
	else
		cout << ret << '\n';
}
