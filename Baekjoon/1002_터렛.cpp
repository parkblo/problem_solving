#include <iostream>
#include <cmath>
using namespace std;

int turretScan(int x1, int y1, int r1, int x2, int y2, int r2)
{
	double d = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));

	if (d == 0 && r1 == r2) return -1;

	int br, sr;
	if (r1 >= r2) {br = r1; sr = r2;}
	else {br = r2; sr = r1;}

	if (r1 + r2 > d && br - sr < d) return 2;
	else if (r1 + r2 == d || br - sr == d) return 1;
	else return 0;
}

int main()
{
	int T;
	int x1, y1, x2, y2, r1, r2;
	cin >> T;
	
	for (int i=0; i<T; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		cout << turretScan(x1, y1, r1, x2, y2, r2) << '\n';
	}

	return 0;
}
