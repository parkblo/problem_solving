#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Pos{
	int a,b;
}pos;

int n;
int numofapt = 0;
int ar[30][30];
int adr[30][30];
int apt[1000] = {0,};
bool vis[30][30] = {false,};
const int da[4] = {0,1,-1,0};
const int db[4] = {1,0,0,-1};
queue<pos> que;

bool Condition(int a, int b)
{
	if (a<0 || b<0 || a>=n || b>=n)
		return false;
	if (adr[a][b] > 0)
		return false;
	if (ar[a][b] != 1)
		return false;
	if (vis[a][b] == true)
		return false;
	
	return true;
}
void bfs(int currA,int currB)
{
	que.push({currA,currB});

	while (!que.empty())
	{
		int frontA = que.front().a;
		int frontB = que.front().b;
		adr[frontA][frontB] = numofapt;
		que.pop();

		for (int i=0; i<4; i++)
		{
			int nextA = frontA + da[i];
			int nextB = frontB + db[i];

			if (Condition(nextA,nextB))
			{
				que.push({nextA,nextB});
				vis[nextA][nextB] = true;
			}
		}
	}
}

void countApt()
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (adr[i][j] > 0)
				apt[adr[i][j]]++;
		}
	}
}

int main()
{
	cin >> n;

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%1d",&ar[i][j]);
			adr[i][j] = 0;
		}
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (ar[i][j] == 1 && adr[i][j] < 1)
			{
				numofapt++;
				bfs(i,j);
			}
		}
	}
	
	countApt();

	sort(apt+1,apt+numofapt+1);

	cout << numofapt << '\n';
	for (int i=1; i<=numofapt ; i++)
		cout << apt[i] << '\n';

	return 0;

}
