#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;

bool isExist(int a, int b)
{
	if (a<=0 || b<=0 || a>n || b>m)
		return false;

	return true;
}

int main()
{
	cin >> n >> m;
	vector<vector<int>> v(n+1,vector<int>(m+1,0));
	
	for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=m; j++)
				cin >> v[i][j];
		}

	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			int val = 0;
			
			if (isExist(i-1,j)){
				val = max(v[i-1][j],val);
			}
			if (isExist(i,j-1)){
				val = max(v[i][j-1],val);
			}
			if (isExist(i-1,j-1)){
				val = max(v[i-1][j-1],val);
			}

			v[i][j] += val;
		}
	}

	cout << v[n][m];
	return 0;
}
