#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int,int> pii;

const int INF = 987654321;
priority_queue<pii,vector<pii>,greater<pii>> pq;
vector<pii> v[1005];
int d[1005];
int n,e;
int start,target;

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
	}
	cin >> start >> target;

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

	cout << d[target] << '\n';
	return 0;
}
