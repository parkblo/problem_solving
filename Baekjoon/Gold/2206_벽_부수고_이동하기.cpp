#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct pos{
	int a,b,cnt,wallCnt;
};

int ans;
int N,M;
int map[1001][1001];
bool visited[1001][1001][2] = {false,};
const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};

int Min(int a,int b) {return a < b ? a : b;}

bool isValid(int a, int b)
{
	if (a<1 || b<1 || a>N || b>M)
		return false;

	return true;
}

void BFS()
{
	queue<pos> que;

	// init
	que.push({1,1,1,0});
	visited[1][1][0] = true;

	while (!que.empty())
	{
		int currA = que.front().a;
		int currB = que.front().b;
		int currCnt = que.front().cnt;
		int currWallCnt = que.front().wallCnt;
		que.pop();

		if (currA == N && currB == M){
			ans = currCnt;
			return;
		}

		for (int i=0; i<4; i++)
		{
			int nextA = currA + dy[i];
			int nextB = currB + dx[i];
			int nextWallCnt;

			//valid check
			if (!isValid(nextA,nextB))
				continue;

			// set nextWallCnt
			if (map[nextA][nextB] == 1)	
				nextWallCnt = currWallCnt + 1;
			else
				nextWallCnt = currWallCnt;

			// already visited
			if (visited[nextA][nextB][nextWallCnt] == true)
				continue;

			// cant break wall more
			if (nextWallCnt >= 2) continue;
			
			que.push({nextA,nextB,currCnt+1,nextWallCnt});
			visited[nextA][nextB][nextWallCnt] = true;
		}
	}

	ans = -1;
}

int main()
{
	scanf("%d %d",&N,&M);

	for (int i=1; i<=N; i++)
	{
		for (int j=1; j<=M; j++)
		{
			scanf("%1d",&map[i][j]);
		}
	}

	BFS();

	printf("%d\n",ans);
	return 0;
}
