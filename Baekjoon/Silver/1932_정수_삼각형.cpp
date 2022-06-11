#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	int tri[502][502]={-1,};
	vector<int> vec;

	cin >> n;

	// input
	int k = 1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=k;j++)
		{
			cin >> tri[i][j];
		}
		k++;
	}

	// DP
	k = 2;
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=k;j++)
		{
			// 시작과 끝에는 못받아 오는 게 있겠 죠? ^^
			if (j == 1)
			{
				tri[i][j] += tri[i-1][j];
			}
			else if (j == k)
			{
				tri[i][j] += tri[i-1][j-1];
			}
			else
			{
				tri[i][j] += max(tri[i-1][j],tri[i-1][j-1]);
			}
		}
		k++;
	}

	// push for sort
	for (int i=1;i<=n;i++)
	{
		vec.push_back(tri[n][i]);
	}
	sort(vec.begin(),vec.end());

	cout << vec[n-1];
	return 0;
}
