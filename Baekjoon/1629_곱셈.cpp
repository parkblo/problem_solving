#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll A, B, C;

ll cal(ll x, ll b)
{
	if (b == 1) return x;

	ll tmp = cal(x, b/2);
	if (b%2==0)
	{
		return tmp*tmp%C;
	}
	else
	{
		return tmp*tmp%C*A%C;
	}
}

int main()
{
	cin >> A >> B >> C;
	cout << cal(A%C, B) << endl;
	return 0;
}
