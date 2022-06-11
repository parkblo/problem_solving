#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

const ll MAX = 9876543210;
int N, M;
vector<int> v;

bool Condition(ll mid)
{
	ll cnt=1;
	ll onepack=0;

	for (int i=0; i<N; i++)
	{
		if(v[i] > mid) return false;

		onepack += v[i];
		if(onepack > mid)
		{
			onepack = v[i];
			cnt++;
		}
	}

	if (cnt <= M) return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i=0; i<N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	ll left=1, right=MAX, mid;
	ll ret = 0;

	while (left <= right)
	{
		// 이분탐색: 가능한 최소 블루레이 크기
		mid = (left+right)/2;

		if (Condition(mid))
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << left << '\n';
	return 0;
}
