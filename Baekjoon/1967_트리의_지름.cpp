#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct Node{
	int to,w;
}node;

int n;
int ans;
vector<node> v[10001];
queue<node> q;

int max(int a, int b){return a > b ? a : b;}

void input()
{
	cin >> n;

	for (int i=0; i<n; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		v[a].push_back({b,c});
	}
}

void BFS()
{
	// 초기 푸쉬
	for (int i=0; i<v[1].size(); i++)
	{
		int currTo = v[1][i].to;
		int currW = v[1][i].w;
		q.push({currTo,currW});
	}

	while (!q.empty())
	{
		int currTo = q.front().to;
		int currW = q.front().w;
		q.pop();

		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


}
