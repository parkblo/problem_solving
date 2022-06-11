#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int &a, int &b){return a<b;}

int main()
{
	vector<int> v;
	int n;
	cin >> n;

	for (int i=0; i<n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), compare);

	int ret=0, last=0;
	for (int i=0; i<n; i++)
	{
		last += v[i];
		ret += last;
	}

	cout << ret << '\n';
	return 0;
}
