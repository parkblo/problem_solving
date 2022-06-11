#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	queue<int> q;
	cin >> n;

	if (n == 1)
	{
		cout << 1 << '\n';
		return 0;
	}

	for (int i=1; i<=n; i++)
		q.push(i);

	int ret = -1;
	while (1)
	{
		q.pop();

		if (q.size() <= 1){
			ret = q.front();
			break;
		}

		int ftmp = q.front();
		q.pop();
		q.push(ftmp);
	}

	cout << ret << '\n';
	return 0;
}
