#include <iostream>
using namespace std;

const int INF = 100000000;
int n,m;
int ar[101][101];

void input()
{
	cin >> n >> m;

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			ar[i][j] = INF;
	
	for (int i=1; i<=m; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		if (c < ar[a][b])
			ar[a][b] = c;
	}
}

void floydWarshall()
{
	for (int k=1; k<=n; k++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				if (ar[i][j] > ar[i][k] + ar[k][j]){
					ar[i][j] = ar[i][k] + ar[k][j];
				}
			}
		}
	}

	// 시작 도시와 도착 도시가 같은 경우는 없다.
	for (int i=1, j=1; i<=n; i++, j++)
		ar[i][j] = 0;
}

void output()
{
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if (ar[i][j] == INF)
				cout << "0 ";
			else
				cout << ar[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	floydWarshall();
	output();

	return 0;
}
