#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 노드의 정보를 저장하는 구조체
typedef struct Node{
	int to,w;
}node;

int n;							// 노드의 개수
int bigidx=1;					// 루트로 부터 가장 가중치 큰노드
int ans=0;						// 출력할 값 (최대 지름)
vector<node> v[100010];			// 노드 저장
queue<node> q;					// BFS를 하기 위한 큐
bool visited[100010] = {false,};	// visited

void input()
{
	cin >> n;
	int a,b,c;

	for (int i=0; i<n; i++)
	{
		cin >> a;
		while (1)
		{
			cin >> b;
			if (b==-1) break;
			cin >> c;
			v[a].push_back({b,c});
		}
	}
}

void visitedClear()
{
	for (int i=0; i<100010; i++)
	{
		visited[i] = false;
	}
}

void BFS()
{
	// 루트를 기점으로 BFS
	for (int i=0; i<v[1].size(); i++)
	{
		int currTo = v[1][i].to;
		int currW = v[1][i].w;
		q.push({currTo,currW});
	}
	visited[1] = true;

	while (!q.empty())
	{
		int currA = q.front().to;
		int currW = q.front().w;
		q.pop();
		
		visited[currA] = true;

		if (currW > ans){
			ans = currW;
			bigidx = currA;
		}

		for (int i=0; i<v[currA].size(); i++)
		{
			int nextA = v[currA][i].to;
			int nextW = v[currA][i].w;

			if (visited[nextA] == true)
				continue;

			q.push({nextA,currW+nextW});
		}
	}

	visitedClear();

	// 가장 가중치가 높은 노드(bigidx)를 기준으로 BFS
	for (int i=0; i<v[bigidx].size(); i++)
	{
		int currTo = v[bigidx][i].to;
		int currW = v[bigidx][i].w;
		q.push({currTo,currW});
	}
	visited[bigidx] = true;

	while (!q.empty())
	{
		int currA = q.front().to;
		int currW = q.front().w;
		q.pop();

		visited[currA] = true;

		if (currW > ans){
			ans = currW;
		}

		for (int i=0; i<v[currA].size(); i++)
		{
			int nextA = v[currA][i].to;
			int nextW = v[currA][i].w;

			if (visited[nextA] == true)
				continue;

			q.push({nextA,currW+nextW});
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	BFS();
	cout << ans << '\n';
	return 0;
}
