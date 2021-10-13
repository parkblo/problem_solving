#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	int ret = -987654321;
	int ar[101];
	cin >> n >> k;

	for (int i=0; i<n; i++)
		cin >> ar[i];
	
	for (int i=0; i<=n-k; i++)
	{
		int sum = 0;
		for (int j=i; j<i+k; j++)
			sum += ar[j];
		ret = max(ret,sum);
	}

	cout << ret << '\n';
	return 0;
}
