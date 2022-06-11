#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

const int MAX_SIZE = 200000+1;
int parent[MAX_SIZE];

int Find(int x)
{
	if (parent[x] < 0)
		return x;
	return parent[x] = Find(parent[x]);
}

int Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y)	return parent[x] * -1;

	if (parent[x] < parent[y])
	{
		parent[x] += parent[y];
		parent[y] = x;
		return parent[x] * -1;
	}
	else
	{
		parent[y] += parent[x];
		parent[x] = y;
		return parent[y] * -1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n,m;

	cin >> n;

	for (int i=0; i<n; i++)
	{
		int hidx = 0;
		unordered_map<string,int> h;

		cin >> m;

		for (int j=0; j<MAX_SIZE; j++)
		{
			parent[j] = -1;
		}

		for (int j=0; j<m; j++)
		{
			string s1, s2;
			cin >> s1 >> s2;

			if (h.find(s1) == h.end())
				h[s1] = hidx++;

			if (h.find(s2) == h.end())
				h[s2] = hidx++;

			cout << Union(h[s1],h[s2]) << '\n';
		}	
	}

	return 0;
}
