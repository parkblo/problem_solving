#include <iostream>
using namespace std;

int N,M;
int t[1025][1025]; // 해당 좌표 까지의 구간합

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
		{
			int num;
			cin >> num;

			t[i+1][j+1] = t[i][j+1] + t[i+1][j] - t[i][j] + num;
		}
	}

	for (int i=0; i<M; i++)
	{
		int a1,a2,b1,b2;
		cin >> a1 >> b1 >> a2 >> b2;

		cout << t[a2][b2] - t[a1-1][b2] - t[a2][b1-1] + t[a1-1][b1-1] << '\n';
	}

	return 0;
}
