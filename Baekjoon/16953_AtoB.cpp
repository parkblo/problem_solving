#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

typedef pair<long long, long long> pll;
queue<pll> q;
const int INF = 1000000001;

// bool visited[1000000001] = {false,}; 겹치는 경우가 없기에 필요없음

int main()
{
	long long ret=0;
	int A, B;

	cin >> A >> B;
	q.push(make_pair(A,0));

	while (!q.empty())
	{
		pll curr = q.front();
		q.pop();
		ret++;

		if(curr.first == B){
			cout << curr.second+1;
			return 0;
		}
		else if(curr.first > B) continue;

		long long next1 = curr.first * 2;
		long long next2 = curr.first * 10 + 1;

		if(next1<INF)
		{
			q.push(make_pair(next1, curr.second + 1));
		}
		if(next2<INF)
		{
			q.push(make_pair(next2, curr.second + 1));
		}
	}

	cout << "-1";
	return 0;
}
