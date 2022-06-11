#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int ar[500001];

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> ar[i];

	sort(ar,ar+n);

	for (int i=0; i<n; i++)
		cout << ar[i] << ' ';
	
	return 0;
}
