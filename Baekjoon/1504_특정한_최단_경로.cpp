#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

const int INF = 987654321;
vector<pii> v[801];
int d[801];
int n, e, v1, v2;

int dijkstra(int start, int desti)
{
	priority_queue<pii,vector<pii>,greater<pii>> pq;

	for (int i=0; i<=n; i++) d[i] = INF;

	d[start] = 0;
	pq.push(make_pair(0,start));

	while (!pq.empty())
	{
		int dst = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (d[curr] < dst) continue;

		for (int i=0; i<v[curr].size(); i++)
		{
			int next = v[curr][i].second;
			int nextDst = dst + v[curr][i].first;

			if (nextDst < d[next])
			{
				d[next] = nextDst;
				pq.push(make_pair(nextDst, next));
			}
		}
	}

	return d[desti];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> e;
	for (int i=0; i<e; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(c,b));
		v[b].push_back(make_pair(c,a));
	}
	cin >> v1 >> v2;

	// 가능한 경우
	// 1 -> v1 -> v2 -> n
	// 1 -> v2 -> v1 -> n

	long long v1first = dijkstra(1,v1) + dijkstra(v1,v2) + dijkstra(v2,n);
	long long v2first = dijkstra(1,v2) + dijkstra(v2,v1) + dijkstra(v1,n);
	// 개선 가능한 점: 1,N인 배열을 받아와서 d[v1] d[v2]를 불러옴으로써 다익스트라 함수를 적게 사용할 수 있다.

	int ret = min(v1first,v2first);

	// 왜인지는 모르겠지만 0보다 ret이 작을 수 있다는 조건이 필요함
	if (ret >= INF || ret <= 0)
		cout << -1 << '\n';
	else
		cout << ret << '\n';
	
	return 0;
}
