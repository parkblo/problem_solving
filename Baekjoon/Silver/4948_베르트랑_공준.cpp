#include <iostream>
using namespace std;

int main()
{
	int ar[246913];
	int m,n;

	while(1)
	{
		cin >> m;
		if (m==0) break;
		n = 2*m;

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

		int ret=0;
		for (int i=m+1; i<=n; i++)
		{
			if (ar[i] != 0)
				ret++;
		}
		cout << ret << '\n';
	}

	return 0;
}
