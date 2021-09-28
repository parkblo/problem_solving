// 아직 풀고 있는 문제입니다.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int ar[21][21];
int ret=1000000000;
bool vis[21] = {false,};

int func(vector<int> start, vector<int> link)
{
	int startValue = 0;
	int linkValue = 0;

	for (int i=1; i<=N/2; i++){
		for (int j=i+1; j<=N/2; j++){
			startValue = startValue + ar[i][j] + ar[j][i];
		}
	}

	for (int i=1; i<=N/2; i++){
		for (int j=i+1; j<=N/2; j++){
			linkValue = linkValue + ar[i][j] + ar[j][i];
		}
	}

	return abs(startValue-linkValue);
}

void solve(vector<int> start, int cnt)
{
	if (cnt == N/2)
	{
		vector<int> link;
		for (int i=1; i<=N; i++)
		{
			if (vis[i] == false)
				link.push_back(i);
		}
		int value = func(start,link);
		if (ret > value){
			cout << value << '\n';
			ret = value;
		}
		return;
	}

	for (int i=1; i<=N; i++)
	{
		if (vis[i] == true) continue;

		vis[i] = true;
		start.push_back(i);
		solve(start,cnt+1);
		vis[i] = false;
	}
}

int main()
{
	cin >> N;

	for (int i=1; i<=N; i++)
		for (int j=1; j<=N; j++)
			cin >> ar[i][j];
	
	vector<int> start;
	solve(start,0);

	cout << ret << '\n';
}
