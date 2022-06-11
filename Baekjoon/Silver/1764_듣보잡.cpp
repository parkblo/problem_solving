#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n,m;
	vector<string> v;
	vector<string> ans;

	cin >> n >> m;

	for (int i=0; i<n+m; i++)
	{
		string stmp;
		cin >> stmp;
		v.push_back(stmp);
	}

	sort(v.begin(),v.end());

	for (int i=1; i<n+m; i++)
	{
		if (v[i-1] == v[i])
			ans.push_back(v[i]);
	}

	cout << ans.size() << '\n';
	for (int i=0; i<ans.size(); i++)
		cout << ans[i] << '\n';
	
	return 0;
}
