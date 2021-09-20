#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int ar[301]; // 해당 계단에 적힌 점수
	int dp[301]; // 해당 계단까지의 최대값
	int n;
	cin >> n;

	for (int i=1; i<=n; i++)
		cin >> ar[i];

	dp[1] = ar[1];
	dp[2] = ar[1]+ar[2]; //max(ar[1],ar[1]+ar[2])에서 후자가 항상큼.
	dp[3] = max(ar[1]+ar[3], ar[2]+ar[3]);

	for (int i=4; i<=n; i++)
		dp[i] = max(ar[i]+dp[i-2], ar[i]+ar[i-1]+dp[i-3]);
	
	/*
	마지막 계단을 구하기 위해 나오는 경우 두가지
	1. 전 계단을 밟았을 경우
		- 전전 계단을 밟으면 3연속이 되므로 전전 계단을 안밟는다는 조건을 추가해줘야 한다. 따라서 ar[i] + ar[i-1] + dp[i-3]
	2. 전 계단을 안밟았을 경우
		- 해당 계단과 전전 계단 최대값 계산. ar[i] + dp[i-2]
	*/

	cout << dp[n];
	return 0;
}
