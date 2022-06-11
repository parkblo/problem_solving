#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T,n;
	cin >> T;
	
	for (int t=0; t<T; t++)	
	{
		// init
		cin >> n;
		vector<string> v(n);
		bool consis = true;

		// input
		for (int i=0; i<n; i++)
			cin >> v[i];
		
		// solve
		sort(v.begin(),v.end());
		for (int i=1; i<n; i++)
		{
			bool flag = true;
			for (int j=0; j<v[i].length() && j<v[i-1].length(); j++)
			{
				if (v[i][j] != v[i-1][j])
				{
					flag = false;
					break;
				}
			}
			if (flag){
				consis = false;
				break;
			}
		}

		if (consis) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
