#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> pii;

int N,K;
int ret = -1;
bool v[1000001] = {false,};
priority_queue<pii,vector<pii>,greater<pii>> pq;

int main()
{
	cin >> N >> K;

	pq.push(make_pair(0,N));
	v[N] = true;

	while (!pq.empty())
	{
		int curTime = pq.top().first;
		int curPos = pq.top().second;
		pq.pop();

		if (curPos == K){
			ret = curTime;
			break;
		}

		if (curPos * 2 < 100001 && !v[curPos * 2])
		{
			pq.push(make_pair(curTime, curPos * 2));
			v[curPos * 2] = true;
		}

		if (curPos + 1 < 100001 && !v[curPos + 1])
		{
			pq.push(make_pair(curTime + 1, curPos + 1));
			v[curPos + 1] = true;
		}

		if (curPos - 1 >= 0 && !v[curPos - 1])
		{
			pq.push(make_pair(curTime + 1, curPos - 1));
			v[curPos - 1] = true;
		}
	}

	cout << ret;
	return 0;
}
