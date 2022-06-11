#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

bool vis[51][51] = {false,};
int ar[51][51];
queue<pair<int,int>> q;
const int da[4] = {-1,1,0,0};
const int db[4] = {0,0,1,-1};

void debug(int n, int m)
{
	for (int i=0;i<n; i++){
		for (int j=0; j<m; j++){
			cout << ar[i][j];
		}
		cout << '\n';
	}
}

int main()
{
	int T, M, N, K;
	cin >> T;

	for (int t=0; t<T; t++){
		cin >> M >> N >> K;

		// init
		for (int i=0;i<M;i++){
			for (int j=0;j<N;j++){
				ar[i][j] = 0;
				vis[i][j] = false;
			}
		}

		for (int i=0; i<K; i++)
		{
			int x, y;
			cin >> x >> y;

			ar[x][y] = 1;
		}

		int ret = 0;

		for (int i=0; i<M; i++){
			for (int j=0; j<N; j++){
				if (ar[i][j] != 1 || vis[i][j]) continue;

				ret++;
				q.push({i,j});
				vis[i][j] = true;
				while (!q.empty())
				{
					int fA = q.front().first;
					int fB = q.front().second;
					q.pop();

					for (int k=0; k<4; k++)
					{
						int nextA = fA + da[k];
						int nextB = fB + db[k];

						if (nextA >= M || nextB >= N || nextA < 0 || nextB < 0 || ar[nextA][nextB] != 1 || vis[nextA][nextB]) continue;
						else
						{
							q.push({nextA,nextB});
							vis[nextA][nextB] = true;
						}
					}
				}
			}
		}

		cout << ret << '\n';
	}
	return 0;
}
