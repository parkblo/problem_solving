#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<ll> v;
ll N, C;

bool compare(ll a, ll b)
{
	return a<b;
}

bool isPossible(ll dst)
{
	bool flag = false;
	int cnt = 1;
	ll base = v[0];

	for (int i=1; i<v.size(); i++)
	{
		if (v[i] - base >= dst)
		{
			cnt++;
			base = v[i];
		}
		if (cnt >= C)
		{
			flag = true;
			break;
		}
	}

	if (flag) return true;
	return false; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll left=0, right=1, mid;
	ll ret=0;
	
	cin >> N >> C;
	
	for (int i=0; i<N; i++)
	{
		ll tmp;
		cin >> tmp;
		v.push_back(tmp);
		right = max(tmp,right);
	}

	sort(v.begin(),v.end(),compare);

	while (left <= right)
	{
		mid = (left+right)/2;

		if (isPossible(mid))
		{
			ret = max(ret, mid);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << ret << '\n';
	return 0;
}
