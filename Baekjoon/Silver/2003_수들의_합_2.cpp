#include <iostream>
using namespace std;

int main()
{
	int n,m;
	int ar[10001];
	cin >> n >> m;

	for (int i=0; i<n; i++)
		cin >> ar[i];
	
	int l = 0, r = 0, sum=0, ret=0;
	while (1)
	{
		if (sum >= m)
		{
			sum -= ar[l];
			l++;
		}
		else if (sum < m)
		{
			if (r == n) break;
			
			sum += ar[r];
			r++;
		}
		
		if (sum == m) ret++;
	}

	cout << ret << '\n';
	return 0;
}
