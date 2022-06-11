#include <vector>
#include <iostream>
using namespace std;

int n, rootidx, del, ret=0;
vector<int> v[51];

void dfs(int curr)
{
	if (del == curr) return;

	bool isLeaf = true;
	
	for (int i=0; i<v[curr].size(); i++)
	{
		if (del == v[curr][i]) continue;
		dfs(v[curr][i]);
		isLeaf = false;
	}

	if (isLeaf) ret++;
}

int main()
{
	cin >> n;

	// input
	for (int i=0; i<n; i++)
	{
		int tmp;
		cin >> tmp;

		if (tmp == -1)
			rootidx = i;
		else
			v[tmp].push_back(i);
	}
	cin >> del;

	// dfs
	dfs(rootidx);

	cout << ret << '\n';
	return 0;
}
