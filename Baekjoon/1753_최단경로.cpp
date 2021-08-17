#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, int> pii;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int V,E,K;
	const int INF = 987654321;
	vector<pii> a[20001];
	priority_queue<pii> pq; 
	int d[20001];
	bool visited[20001]= {false,};

	cin >> V >> E;
	cin >> K;

	for (int i=1; i<=E; i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		a[u].push_back(make_pair(w,v));
		// C++에서 std::pair는 first끼리를 먼저 비교하고, first가 같으면 second를 비교합니다. 이게 무슨 뜻이냐면, pair<int, int>로 우선순위 큐에 원소를 넣는다면 반드시 first에 거리가 들어가야 한다는 뜻입니다. 정점 번호끼리의 비교에는 아무런 의미가 없습니다. 물론 직접 비교 함수를 정의해서 second를 먼저 보게 만들 수는 있습니다.
	}

	for (int i=1; i<=V; i++) d[i] = INF;

	// dijkstra ===============
	d[K] = 0;
	pq.push(make_pair(0, K));
	
	while(!pq.empty())
	{
		int current = pq.top().second;
		int distance = -pq.top().first; // for greater
		pq.pop();

		for (int i=0; i<a[current].size(); i++)
		{
			int next = a[current][i].second; 
			int nextDistance = distance + a[current][i].first;

			if(nextDistance < d[next])
			{
				d[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
	// ========================

	for (int i=1; i<=V; i++)
	{
		if (d[i] == INF)
			cout << "INF\n";
		else
			cout << d[i] << '\n';
	}

	return 0;
}
