#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);

	for (int i=n-1; i>=0; i--)
		cin >> v[i];

	int cnt = 0;
	for (int i=0; i<n; i++)
	{
		if (k <= 0) break;

		cnt += k / v[i];
		k %= v[i];
	}

	cout << cnt << '\n';
	return 0;
}
