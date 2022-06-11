#include <iostream>
using namespace std;

int main()
{
	int ar[1000001];
	int m,n;
	cin >> m >> n;

	for (int i=1; i<=n; i++)
		ar[i] = i;

	for (int i=1; i<=n; i++)
	{
		if (i==1)
		{
			ar[i] = 0;
			continue;
		}
		if (ar[i] == 0) continue;

		for (int j=i+i; j<=n; j+=i)
		{
			ar[j] = 0;
		}
	}

	for (int i=m; i<=n; i++)
	{
		if (ar[i] != 0)
			cout << ar[i] << '\n';
	}

	return 0;
}
