#include <iostream>
#include <cmath>
using namespace std;

int N;
int ar[100001];

int main()
{
	cin >> N;
	for (int i=0; i<N; i++)
		cin >> ar[i];

	int l = 0, r = N-1;
	int retA=0, retB=0, ret=2000000001;

	while (l < r)
	{
		int diff = ar[l] + ar[r];
		if (abs(diff) < ret)
		{
			ret = abs(diff);
			retA = l; retB = r;
		}

		if (diff > 0)
			r--;
		else
			l++;
	}

	cout << ar[retA] << ' ' << ar[retB] << '\n';

	return 0;
}
