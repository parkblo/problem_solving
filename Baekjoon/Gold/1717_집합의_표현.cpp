#include <iostream>
using namespace std;

const int MAX_SIZE = 1000000+1;
int depth[MAX_SIZE];
int parent[MAX_SIZE];
int n,m;

int Find(int x)
{
	if (parent[x] == x)
		return x;
	else
	{
		int y = Find(parent[x]);
		parent[x] = y;
		return y;
	}
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y)	return;

	if (depth[x] > depth[y])
	{
		parent[y] = x;
		depth[x] += depth[y];
	}
	else
	{
		parent[x] = y;
		depth[y] += depth[x];
	}
}

bool isSameUnion(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y) return true;
	else return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	// init
	for (int i=1; i<=n; i++)
	{
		depth[i] = 1;
		parent[i] = i;
	}

	// UNION FIND
	for (int i=0; i<m; i++)
	{
		int c,a,b;
		cin >> c >> a >> b;

		if (c == 0)
			Union(a,b);
		else if (c == 1)
		{
			bool condition = isSameUnion(a,b);

			if (condition) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}

	return 0;
}
