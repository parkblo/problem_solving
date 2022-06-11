#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int ar[300001];

bool f(int mid)
{
	int cnt=0;

	for (int i=0; i<m; i++){
		cnt += ar[i] / mid;
		if (ar[i]%mid)
			cnt++;
	}

	return n >= cnt;
}

int main()
{
	cin >> n >> m;
	

	int left = 1, right = 0, ret=1987654321;
	
	for (int i=0; i<m; i++){
		cin >> ar[i];
		right = max(right,ar[i]);
	}

	while (left <= right)
	{
		int mid = (left+right)/2;

		if (f(mid)){
			right = mid - 1;
			ret = min(ret,mid);
		}
		else{
			left = mid + 1;
		}
	}

	cout << ret << '\n';
	return 0;
}
