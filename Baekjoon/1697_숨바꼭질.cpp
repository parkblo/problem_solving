#include <iostream>
#include <queue>
using namespace std;

typedef struct Pos{
	int a,t;
}pos;

int ret=0;
bool vis[100001] = {false,};
int n, k;
queue<pos> q;

bool Condition(int a)
{
	if (a<0 || a>100000)
		return false;
	if (vis[a] == true)
		return false;
	
	return true;
}


int main()
{
	cin >> n >> k;

	q.push({n,0});
	vis[n] = true;

	while (!q.empty())
	{
		int frontA = q.front().a;
		int frontT = q.front().t;
		q.pop();

		if (frontA == k){
			ret = frontT;
			break;
		}

		if (Condition(frontA*2)){
			q.push({frontA*2,frontT+1});
			vis[frontA*2] = true;
		}
		if (Condition(frontA-1)){
			q.push({frontA-1,frontT+1});
			vis[frontA-1] = true;
		}
		if (Condition(frontA+1)){
			q.push({frontA+1,frontT+1});
			vis[frontA+1] = true;
		}
	}

	cout << ret << '\n';
	return 0;
}
