#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int ar[21][21];
int ret=1000000000;
bool vis[21] = {false,};

void printV(vector<int> start, vector<int> link)
{
	for (int i=0; i<start.size(); i++)
		cout << start[i] << ' ';
	cout << '\n';
	for (int i=0; i<link.size(); i++)
		cout << link[i] << ' ';
	cout << '\n';
}

int func(vector<int> start, vector<int> link)
{
	int startValue = 0;
	int linkValue = 0;

	for (int i=0; i<start.size(); i++){
		for (int j=0; j<start.size(); j++){
			if (i==j) continue;
			startValue += ar[start[i]][start[j]];
		}
	}

	for (int i=0; i<link.size(); i++){
		for (int j=0; j<link.size(); j++){
			if (i==j) continue;
			linkValue += ar[link[i]][link[j]];
		}
	}

	return abs(startValue-linkValue);
}

void solve(int idx, int cnt)
{
	if (cnt == N/2)
	{
		vector<int> start;
		vector<int> link;
		for (int i=1; i<=N; i++)
		{
			if (vis[i]) start.push_back(i);
			else link.push_back(i);
		}
		int value = func(start,link);
		if (ret > value)
			ret = value;
		return;
	}

	for (int i=idx; i<=N; i++)
	{
		if (vis[i] == true) continue;

		vis[i] = true;
		solve(i+1, cnt+1);
		vis[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;

	for (int i=1; i<=N; i++)
		for (int j=1; j<=N; j++)
			cin >> ar[i][j];
	
	solve(1,0);

	cout << ret << '\n';
}
