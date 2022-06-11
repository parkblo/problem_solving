#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, pair<int, int>> pii;

int N,M;
vector<vector<int>> tom;
queue<pii> que;
int all=0, ripen=0, cnt=0, ret=0, tmp;

bool checkAvailable(int a, int b)
{
	if (a<0 || b<0 || a>=N || b>=M) return false;

	if (tom[a][b] == 0) return true;
	else return false;
}

int main()
{
	cin >> M >> N;
	tom.resize(N,vector<int>(M));

	for (int i=0; i<N; i++) //input
	{
		for (int j=0; j<M; j++)
		{
			cin >> tom[i][j];
			if (tom[i][j] == 1){
				all++; ripen++;
				que.push(make_pair(i,make_pair(j,cnt)));
			}
			else if (tom[i][j] == 0){
				all++;
			}
		}
	}

	if (que.empty()){
		cout << "-1\n";
		return 0;
	}
	while (!que.empty())
	{
		int a = que.front().first;
		int b = que.front().second.first;
		ret = que.front().second.second;

		que.pop();
		if (checkAvailable(a-1,b))
		{
			que.push(make_pair(a-1,make_pair(b,ret+1)));
			tom[a-1][b] = 1;
			ripen++;
		}
		if (checkAvailable(a+1,b))
		{
			que.push(make_pair(a+1,make_pair(b,ret+1)));
			tom[a+1][b] = 1;
			ripen++;
		}
		if (checkAvailable(a,b-1))
		{
			que.push(make_pair(a,make_pair(b-1,ret+1)));
			tom[a][b-1] = 1;
			ripen++;
		}
		if (checkAvailable(a,b+1))
		{
			que.push(make_pair(a,make_pair(b+1,ret+1)));
			tom[a][b+1] = 1;
			ripen++;
		}
	}

	if (ripen < all) {cout << "-1\n";}
	else {cout << ret;}

	return 0;
}
