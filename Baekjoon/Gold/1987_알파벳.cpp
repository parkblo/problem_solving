#include <iostream>
#include <queue>
using namespace std;

typedef struct Pos{
	int a,b,len;
}pos;

int R,C,ret=0;
char alp[21][21];
bool v[100] = {false,}; //'char to int' visited array
queue<pos> que;
const int da[4] = {0, 0, 1, -1};
const int db[4] = {1, -1, 0, 0};

bool isValidPosition(int a, int b)
{
	if (a<0 || b<0 || a>=R || b>=C)
		return false;
	
	if (v[alp[a][b]] == true)
		return false;

	return true;
}

void dfs(int currA, int currB, int currL)
{
	if (currL > ret)
		ret = currL;
	
	for (int i=0; i<4; i++)
	{
		int nextA = currA + da[i];
		int nextB = currB + db[i];
		int nextL = currL + 1;

		v[alp[currA][currB]] = true;

		if(isValidPosition(nextA, nextB))
			dfs(nextA,nextB,nextL);

		v[alp[currA][currB]] = false;
	}
}

int main()
{
	cin >> R >> C;
	for (int i=0; i<R; i++)
		for (int j=0; j<C; j++)
			cin >> alp[i][j];

	dfs(0,0,1);

	cout << ret << '\n';
	return 0;
}
