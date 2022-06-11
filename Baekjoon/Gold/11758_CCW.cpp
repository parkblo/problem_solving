#include <iostream>
using namespace std;

int CCW(int x1, int y1, int x2, int y2, int x3, int y3)
{
	int a = x1 * y2 + x2 * y3 + x3 * y1;
	int b = y1 * x2 + y2 * x3 + y3 * x1;

	if (a - b > 0) return 1;
	else if (a - b < 0) return -1;
	else return 0;
}

int main()
{
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	cout << CCW(x1, y1, x2, y2, x3, y3);
	return 0;
}
