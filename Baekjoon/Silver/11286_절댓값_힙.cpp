#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct compare{
	bool operator()(int a, int b)
	{
		if (abs(a) < abs(b))
			return false;
		else if (abs(a) > abs(b))
			return true;
		
		// abs 동일 시
		if (a < b)
			return false;
		else
			return true;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	priority_queue<int, vector<int>, compare> pq;

	int T;
	cin >> T;
	for (int i=0; i<T; i++)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 0)
		{
			if (pq.empty())
			{
				cout << 0 << '\n';
				continue;
			}

			int pqf = pq.top();
			cout << pqf << '\n';
			pq.pop();
		}
		else
		{
			pq.push(cmd);
		}
	}

	return 0;
}
