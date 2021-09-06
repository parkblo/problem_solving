#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main()
{
	ll X, Y;
	double Z;
	
	ll left=1, right=1000000000, mid;
	ll ret=9876543210;
	
	cin >> X >> Y;
	ll pastz = Y*100 / X;

	// 예외
	if (pastz >= 99)
	{
		cout << "-1" << '\n';
		return 0;
	}

	while (left <= right)
	{
		mid = (left+right)/2;

		ll nowz = (Y+mid) * 100 / (X+mid);

		if (pastz < nowz)
		{
			ret = min(ret,mid);
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	if (ret==9876543210) cout << "-1" << '\n';
	else cout << ret << '\n';

	return 0;
}
