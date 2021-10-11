#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int INF = 987654321;
int n, e, t;
int s, g, h;

vector<int> dijkstra(vector<pii> v[2001], int start)
{
	priority_queue<pii,vector<pii>,greater<pii>> pq;

	vector<int> d(n+1,INF);

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

	return d;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int p=0; p<T; p++)
	{

		// input
		cin >> n >> e >> t;
		cin >> s >> g >> h;

		vector<int> xv(t);
		vector<pii> v[2001];

		for (int i=0; i<e; i++)
		{
			int a,b,c;
			cin >> a >> b >> c;
			v[a].push_back(make_pair(c,b));
			v[b].push_back(make_pair(c,a));
		}
		for (int i=0; i<t; i++)
			cin >> xv[i];

		// solve
		// 가능한 경우
		// 1. 출발점 -> g -> h -> xv
		// 2. 출발점 -> h -> g -> xv

		vector<int> fromS = dijkstra(v,s);
		vector<int> fromG = dijkstra(v,g);
		vector<int> fromH = dijkstra(v,h);

		sort(xv.begin(),xv.end());

		// print
		for (int i=0; i<t; i++)
		{
			if (fromS[xv[i]] != INF && fromS[g] + fromG[h] + fromH[xv[i]] == fromS[xv[i]])
				cout << xv[i] << ' ';
			else if (fromS[xv[i]] != INF && fromS[h] + fromH[g] + fromG[xv[i]] == fromS[xv[i]])
				cout << xv[i] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
