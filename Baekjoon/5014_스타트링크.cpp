#include <iostream>
#include <queue>
using namespace std;

struct elev{
	int curr, cnt;
};

int f,s,g,u,d;
bool vis[1000001] = {false,};

bool Condition(int a)
{
	if (a > f || a < 1 || vis[a])
		return false;
	
	return true;
}

int main()
{
	queue<elev> q;

	cin >> f >> s >> g >> u >> d;

	if (s == g)
	{
		cout << 0 << '\n';
		return 0;
	}

	q.push({s,0});
	vis[s] = true;

	while (!q.empty())
	{
		int fCurr = q.front().curr;
		int fCnt = q.front().cnt;
		q.pop();
		
		if (fCurr == g)
		{
			cout << fCnt << '\n';
			return 0;
		}

		if (Condition(fCurr+u)){
			q.push({fCurr+u,fCnt+1});
			vis[fCurr+u] = true;
		}
		if (Condition(fCurr-d)){
			q.push({fCurr-d,fCnt+1});
			vis[fCurr-d] = true;
		}
	}

	cout << "use the stairs\n";
	return 0;
}
