#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct pos{
	int a,b,cnt;
};

int n,m;
queue<pos> q;
int ar[101][101];
bool vis[101][101] = {false,};
const int da[4] = {-1,1,0,0};
const int db[4] = {0,0,-1,1};

bool Condition(int a, int b)
{
	if (a<1 || b<1 || a>n || b>m 
	|| vis[a][b] || ar[a][b] == 0)
		return false;
	
	return true;
}

int main()
{
	cin >> n >> m;

	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			scanf("%1d",&ar[i][j]);
		}
	}

	q.push({1,1,1});
	vis[1][1] = true;

	while (!q.empty())
	{
		int fa = q.front().a;
		int fb = q.front().b;
		int fcnt = q.front().cnt;
		q.pop();

		if (fa == n && fb == m)
		{
			cout << fcnt << '\n';
			return 0;
		}

		for (int i=0; i<4; i++)
		{
			int nextA = fa + da[i];
			int nextB = fb + db[i];

			if (Condition(nextA,nextB))
			{
				q.push({nextA,nextB,fcnt+1});
				vis[nextA][nextB] = true;
			}
		}
	}
}
