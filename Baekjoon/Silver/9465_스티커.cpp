#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t,n;
	int s[2][100001];
	int dp[2][100001];

	cin >> t;
	for (int i=0; i<t; i++){
		cin >> n;

		for (int j=0; j<2; j++){
			for (int k=1; k<=n; k++){
				cin >> s[j][k];
			}
		}
		s[0][0] = s[1][0] = 0;
		dp[0][1] = s[0][1];
		dp[1][1] = s[1][1];

		for (int k=2; k<=n; k++){
			dp[1][k] = max(dp[0][k-1], dp[0][k-2]) + s[1][k];
			dp[0][k] = max(dp[1][k-1], dp[1][k-2]) + s[0][k];
		}
		cout << max(dp[0][n],dp[1][n]) << '\n';
	}
}
