#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<int> v;
int n,m;

bool f(int mid)
{
	int now_money=mid, num=1;
	for (int i=0; i<n; i++)
	{
		if (v[i] > mid) // 모순
			return false;

		if (v[i] > now_money)  // 인출이 필요함
		{
			num++;
			now_money = mid;
		}
		now_money -= v[i];
	}

	if (num <= m) return true;
	return false;
}

int main()
{
	int left=1, right=0, mid;
	int ret=0;

	cin >> n >> m;
	for (int i=0; i<n ;i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		right += tmp;
	}

	while (left<=right)
	{
		mid = (left+right)/2; //조건 내 K 이분탐색

		if (f(mid)) // m번 이하로 인출로 끝낼 수 있음
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
