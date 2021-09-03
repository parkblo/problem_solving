#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int K,N;
vector<ll> v;

bool isPossible(ll cut)
{
	ll cnt=0;

	for (int i=0; i<K; i++)
		cnt += v[i] / cut;

	if (cnt >= N)
		return true;
	else
		return false;
}

int main()
{
	ll ret=0;
	ll left=1, right=2, mid;

	cin >> K >> N;
	for (int i=0; i<K; i++)
	{
		ll tmp;
		cin >> tmp;
		v.push_back(tmp);
		right = max(right, tmp);
	}

	// Binary Search
	while (left <= right)
	{
		mid = (left+right)/2;

		if (isPossible(mid))
		{
			ret = max(ret,mid);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << ret << '\n';
}
