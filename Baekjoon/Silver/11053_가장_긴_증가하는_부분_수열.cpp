#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int arr[1001];
	int DP[1001];
	int N;
	int ret=0;

	// input
	cin >> N;
	for (int i=0; i<N; i++) cin >> arr[i];

	// solve
	for (int i=0; i<N; i++)
	{
		DP[i] = 1;
		for (int j=i-1; j>=0; j--)
		{
			if (arr[i] > arr[j])
				DP[i] = max(DP[i], DP[j]+1);
		}
		ret = max(ret, DP[i]);
	}

	cout << ret << endl;
	return 0;
}
