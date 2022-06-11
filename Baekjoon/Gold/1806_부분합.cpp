#include <iostream>
using namespace std;

int ar[100001];
int dp[100001];
int minLen = 100010;
int N,S;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> S;
	for (int i=0; i<N; i++)
		cin >> ar[i];
	
	dp[0] = ar[0];
	for (int i=1; i<N; i++)
		dp[i] = dp[i-1] + ar[i];

	int l=0, r=0;
	while (r < N)
	{
		int val;
		int len = r-l+1;
		if (l==0) val = dp[r];
		else val = dp[r] - dp[l-1];

		if (val < S)
		{
			r++;
		}
		else
		{
			if (minLen > len)
				minLen = len;
			l++;
		}

		if (minLen == 1) break; // 1보다 더 작은건 불가
	}

	if (minLen != 100010) cout << minLen << '\n';
	else cout << 0 << '\n';
	return 0;
}
