#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num[1000001], N;
	cin >> N;

	for (int i=2; i<=N; i++)
	{
		num[i] = num[i-1] + 1;
		if (i%2==0) num[i] = min(num[i], num[i/2]+1);
		if (i%3==0) num[i] = min(num[i], num[i/3]+1);
	}

	cout << num[N];
	return 0;
}
