#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num[1000001], N;
	int path[1000001];
	cin >> N;

	num[1] = 0; path[1] = 0;
	for (int i=2; i<=N; i++)
	{
		num[i] = num[i-1] + 1;
		path[i] = i-1;
		if (i%2==0 && num[i] > num[i/2]+1)
		{
			num[i] = num[i/2]+1;
			path[i] = i/2;
		}
		if (i%3==0 && num[i] > num[i/3]+1)
		{
			num[i] = num[i/3]+1;
			path[i] = i/3;
		}
	}

	// 연산 회수 출력
	cout << num[N] << '\n';

	// 역추적 결과 출력
	cout << N << ' ';
	int curr=N;
	while (curr > 1)
	{
		cout << path[curr] << ' ';
		curr = path[curr];
	}

	return 0;
}
