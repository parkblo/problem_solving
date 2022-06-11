#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<ll> v;
ll N, M;

bool isPossible(ll cut)
{

	ll allLen=0;
	bool flag=false;

	for (int i=0; i<N; i++)
	{
		if (v[i]-cut>0) 
			allLen = allLen + v[i] - cut;
		
		if (allLen >= M)
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

	ll left=1, right=1, mid;
	ll ret=0;
	
	cin >> N >> M;
	
	for (int i=0; i<N; i++)
	{
		ll tmp;
		cin >> tmp;
		v.push_back(tmp);
		right = max(tmp,right);
	}

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
