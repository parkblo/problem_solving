#include <iostream>
using namespace std;
#define ll long long

int CCW(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3)
{
	ll outer = x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1;

	if (outer > 0) return 1;
	else if (outer == 0) return 0;
	else return -1;
}

int main()
{
	ll x1,x2,x3,x4,y1,y2,y3,y4;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	int ABC = CCW(x1,x2,x3,y1,y2,y3);
	int ABD = CCW(x1,x2,x4,y1,y2,y4);
	int CDA = CCW(x3,x4,x1,y3,y4,y1);
	int CDB = CCW(x3,x4,x2,y3,y4,y2);

	int AB = ABC * ABD;
	int CD = CDA * CDB;
	if (AB <= 0 && CD <= 0) cout << 1 << '\n';
	else cout << 0 << '\n'; 

	return 0;
}
