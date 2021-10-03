// 복습 필요

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
	ll n,k;
	ll ret=0;

	cin >> n;
	cin >> k;

	ll left=1, right=k, mid;
	while (left <= right)
	{
		ll cnt=0;
		mid = (left + right) / 2;

		for (ll i=1; i<=n; i++)
			cnt += min(n, mid / i);
		
		if (cnt >= k)
		{
			ret = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ret << '\n';
	return 0;
}
