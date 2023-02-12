#include <iostream>
using namespace std;

int main()
{
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	int minh=2001,mind=2001;
	if (minh>=a) minh=a;
	if (minh>=b) minh=b;
	if (minh>=c) minh=c;
	if (mind>=d) mind=d;
	if (mind>=e) mind=e;

	cout << minh+mind-50 << '\n';
	return 0;
}
