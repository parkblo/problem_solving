#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int ar[300001];

	int n;
	cin >> n;

	for (int i=1; i<=3*n; i++)
		cin >> ar[i];

	sort(ar+1,ar+3*n+1);

	cout << ar[n*2] - ar[1+n] << '\n';
	return 0;
}
