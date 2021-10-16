#include <iostream>
using namespace std;

int main()
{
	int n,ret=0;
	cin >> n;

	for (int i=1; i<=n; i++)
	{
		if (i>=1 && i<=99)
		{
			ret++;
			continue;
		}
		else
		{
			bool flag = false;
			int tmp = i/100;
			int gap = i%10 - i/10%10;
			int before = i/10%10;

			while (tmp > 0)
			{
				if (before - gap != tmp%10)
				{
					flag = true;
					break;
				}
				before = tmp%10;
				tmp /= 10;
			}

			if (!flag) ret++;
		}
	}

	cout << ret << '\n';
	return 0;
}
