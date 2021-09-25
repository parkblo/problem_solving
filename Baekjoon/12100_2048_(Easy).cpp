#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int N;
int maxBlock=0;
queue<int> que;
const int da[4] = {0,0,-1,1};
const int db[4] = {-1,1,0,0};
// left, right, up, down 순서

vector<vector<int>> play2048(vector<vector<int> > v, int dir)
{
	if (dir==0) //LEFT
	{
		for (int i=0;i<N;i++)
		{
			for (int j=0;j<N;j++)
			{
				if (v[i][j] != 0)
					que.push(v[i][j]);
			}

			for (int j=0;j<N;j++)
			{
				if (!que.empty())
				{
					v[i][j] = que.front();
					que.pop();
					if (!que.empty() && v[i][j] == que.front())
					{
						v[i][j] *= 2;
						que.pop();
					}
					continue;
				}
				v[i][j] = 0;
			}
		}
	}
	else if (dir==1) //RIGHT
	{
		for (int i=0;i<N;i++)
		{
			for (int j=N-1;j>=0;j--)
			{
				if (v[i][j] != 0)
					que.push(v[i][j]);
			}

			for (int j=N-1;j>=0;j--)
			{
				if (!que.empty())
				{
					v[i][j] = que.front();
					que.pop();
					if (!que.empty() && v[i][j] == que.front())
					{
						v[i][j] *= 2;
						que.pop();
					}
					continue;
				}
				v[i][j] = 0;
			}
		}
	}
	else if (dir==2) //UP
	{
		for (int j=0;j<N;j++)
		{
			for (int i=0;i<N;i++)
			{
				if (v[i][j] != 0)
					que.push(v[i][j]);
			}

			for (int i=0;i<N;i++)
			{
				if (!que.empty())
				{
					v[i][j] = que.front();
					que.pop();
					if (!que.empty() && v[i][j] == que.front())
					{
						v[i][j] *= 2;
						que.pop();
					}
					continue;
				}
				v[i][j] = 0;
			}
		}
	}
	else if (dir==3) //DOWN
	{
		for (int j=0;j<N;j++)
		{
			for (int i=N-1;i>=0;i--)
			{
				if (v[i][j] != 0)
					que.push(v[i][j]);
			}

			for (int i=N-1;i>=0;i--)
			{
				if (!que.empty())
				{
					v[i][j] = que.front();
					que.pop();
					if (!que.empty() && v[i][j] == que.front())
					{
						v[i][j] *= 2;
						que.pop();
					}
					continue;
				}
				v[i][j] = 0;
			}
		}
	}
	return v;
}

int findBiggestNum(vector<vector<int> > v)
{
	int ret=0;
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			if (ret < v[i][j])
				ret = v[i][j];
		}
	}

	return ret;
}

void dfs(vector<vector<int> > v, int dir, int cnt)
{
	if (cnt == 5)
	{
		int currBiggest = findBiggestNum(v);

		if(maxBlock < currBiggest){
			maxBlock = currBiggest;
		}
		
		return;
	}

	v = play2048(v, dir);

	for (int i=0; i<4; i++)
		dfs(v,i,cnt+1);
}

int main()
{
	cin >> N;
	vector<vector<int> > v(N, vector<int>(N,0));
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			cin >> v[i][j];

	for (int i=0; i<4; i++)
		dfs(v,i,0);

	cout << maxBlock << '\n';
	return 0;
}
