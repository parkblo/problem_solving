#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T;
	cin >> T;
	for (int t=0; t<T; t++){
		int a,b;
		cin >> a >> b;
		int ta = a;
		
		for (int i=1; i<b; i++){
			a *= ta;
			a %= 10;
		}

		if (b == 1) a %= 10;
		if (a == 0) a = 10;
		
		cout << a << '\n';
	}
	return 0;
}
