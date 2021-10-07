#include <queue>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	cin >> n;

	for (int i=1; i<=n*n; i++)
	{
		int tmp;
		cin >> tmp;
		pq.push(tmp);
		if (pq.size() > n)
		{
			pq.pop();
		}
	}
	
	cout << pq.top() << '\n';
}
