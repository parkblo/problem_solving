#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

int lab[8][8];
int cpylab[8][8];
int n, m; 			//3<=n,m<=8
vector<pii> e; 		//empty space
vector<pii> vir; 	//virus exist space
queue<pii> q; 		//for BFS
int ret=0;			//return value
const int dy[4] = {1, 0, 0, -1};
const int dx[4] = {0, -1, 1, 0};

// 원본을 수정하지 않게 배열 복사
void labToCpylab()
{
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cpylab[i][j] = lab[i][j];
		}
	}
}

// cpylab에서 0인 공간을 세서 반환
int countSafeSpace()
{
	int cnt=0;

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (cpylab[i][j] == 0) cnt++;
		}
	}

	return cnt;
}

// 바이러스가 번식할 수 있는 공간인지 확인
bool canVirusIncrease(int a, int b)
{
	if (a<0 || b<0 || a>=n || b>=m)
		return false;
	
	if (cpylab[a][b] == 0) return true;
	
	return false;
}

void solve(int c)
{
	// 벽이 3개가 세워졌을 시 BFS
	if (c == 3)
	{
		labToCpylab();

		for (int i=0; i<vir.size(); i++)
		{
			int va = vir[i].first;
			int vb = vir[i].second;
			q.push(make_pair(va,vb));
		}
		
		while (!q.empty())
		{
			int fa = q.front().first;
			int fb = q.front().second;
			q.pop();

			for (int i=0; i<4; i++)
			{
				int dda = fa + dy[i];
				int ddb = fb + dx[i];
				if ((canVirusIncrease(dda, ddb)) == true){
					q.push(make_pair(dda,ddb));
					cpylab[dda][ddb] = 2;
				}
			}
		}
		ret = max(ret,countSafeSpace());
		return;
	}

	// 벽 세우기
	for (int i=0; i<e.size(); i++)
	{
		int a = e[i].first;
		int b = e[i].second;

		if (lab[a][b] != 0) continue;

		lab[a][b] = 1;
		solve(c+1);
		lab[a][b] = 0;
	}
}

int main()
{
	cin >> n >> m;

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> lab[i][j];

			if (lab[i][j] == 0){
				e.push_back(make_pair(i,j));
			}
			else if (lab[i][j] == 2){
				vir.push_back(make_pair(i,j));
			}
		}
	}

	solve(0);

	cout << ret;
	return 0;
}
