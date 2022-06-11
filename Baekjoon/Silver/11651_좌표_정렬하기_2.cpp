#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct pos{
	int a,b;
};

vector<pos> v;

bool compare(pos &v1, pos &v2)
{
	if (v1.b < v2.b)
		return true;
	if (v1.b == v2.b && v1.a < v2.a)
		return true;
	
	return false;
}

int main()
{
	int n;
	cin >> n;

	for (int i=0; i<n; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		v.push_back({tmp1,tmp2});
	}
	sort(v.begin(),v.end(),compare);

	for (int i=0; i<n; i++)
	{
		cout << v[i].a << ' ' << v[i].b << '\n';
	}
	return 0;
}
