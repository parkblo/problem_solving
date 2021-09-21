#include <iostream>
#define MOD 1000000000
using namespace std;

/*

<점화식>

DP[i][j] = DP[i-1][j-1] + DP[i-1][j+1]
DP[i][j]는 'i는 길이, j는 마지막 수'일 때의 계단수

하지만 j가 0과 9라면 식이 조금 다르다.
DP[i][0] = DP[i-1][j+1] => 이전 마지막 수가 0만됨
DP[i][9] = DP[i-1][j-1] => 이전 마지막 수가 8만됨

*/

int main()
{
	int dp[101][11];
	int n;
	int sum = 0;

	cin >> n;

	dp[1][0] = 0;
	for (int i=1; i<=9; i++)
		dp[1][i] = 1;

	for (int i=2; i<=n; i++)
	{
		for (int j=0; j<=9; j++)
		{
			if (j==0) dp[i][j] = dp[i-1][j+1];
			else if (j==9) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];

			dp[i][j] = dp[i][j] % MOD;
		}
	}

	for (int i=0; i<=9; i++)
		sum = (sum + dp[n][i]) % MOD;

	cout << sum;
	return 0;
}
