#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
typedef pair<pair<int, int>, pair<int, int>> pii;

int N,M,H;
int ***tom;

queue<pii> que;
int all=0, ripen=0, cnt=0, ret=0;

bool checkAvailable(int a, int b, int c)
{
	if (a<0 || b<0 || c<0 || a>=N || b>=M || c>=H) return false;

	if (tom[a][b][c] == 0) return true;
	else return false;
}

int main()
{
	cin >> M >> N >> H;

	// init
	tom = (int ***)malloc(sizeof(int **)*N);
	for (int i=0; i<N; i++){
		tom[i] = (int **)malloc(sizeof(int*)*M);
	}
	for (int i=0; i<N;i++){
		for (int j=0; j<M; j++){
			tom[i][j] = (int *)malloc(sizeof(int)*H);
		}
	}

	// input
	for (int p=0; p<H; p++)
	{
		for (int i=0; i<N; i++)
		{
			for (int j=0; j<M; j++){
				cin >> tom[i][j][p];
				if (tom[i][j][p] == 1){
					all++; ripen++;
					que.push(make_pair(make_pair(i,j),make_pair(p,cnt)));
				}
				else if (tom[i][j][p] == 0){
					all++;
				}
			}
		}
	}

	if (que.empty()){
		cout << "-1\n";
		return 0;
	}

	while (!que.empty())
	{
		int n = que.front().first.first;
		int m = que.front().first.second;
		int h = que.front().second.first;
		ret = que.front().second.second;

		que.pop();

		if (checkAvailable(n-1,m,h))
		{
			que.push(make_pair(make_pair(n-1,m),make_pair(h,ret+1)));
			tom[n-1][m][h] = 1;
			ripen++;
		}
		if (checkAvailable(n+1,m,h))
		{
			que.push(make_pair(make_pair(n+1,m),make_pair(h,ret+1)));
			tom[n+1][m][h] = 1;
			ripen++;
		}
		if (checkAvailable(n,m-1,h))
		{
			que.push(make_pair(make_pair(n,m-1),make_pair(h,ret+1)));
			tom[n][m-1][h] = 1;
			ripen++;
		}
		if (checkAvailable(n,m+1,h))
		{
			que.push(make_pair(make_pair(n,m+1),make_pair(h,ret+1)));
			tom[n][m+1][h] = 1;
			ripen++;
		}
		if (checkAvailable(n,m,h-1))
		{
			que.push(make_pair(make_pair(n,m),make_pair(h-1,ret+1)));
			tom[n][m][h-1] = 1;
			ripen++;
		}
		if (checkAvailable(n,m,h+1))
		{
			que.push(make_pair(make_pair(n,m),make_pair(h+1,ret+1)));
			tom[n][m][h+1] = 1;
			ripen++;
		}
	}

	if (ripen < all) {cout << "-1\n";}
	else {cout << ret;}

	return 0;
}
