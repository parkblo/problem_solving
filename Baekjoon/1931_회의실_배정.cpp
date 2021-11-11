#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Time{
	int s,e;
};

bool compare(struct Time &a, struct Time &b)
{
	if (a.e == b.e) return a.s < b.s;
	return a.e < b.e;
}

int main()
{
	int n;
	vector<Time> t;
	cin >> n;

	for (int i=0; i<n; i++)
	{
		int start,end;
		cin >> start >> end;
		t.push_back({start,end});
	}

	sort(t.begin(),t.end(),compare);

	int cnt = 0;
	int lastEnd = -1;
	for (int i=0; i<n; i++)
	{
		if (t[i].s >= lastEnd)
		{
			lastEnd = t[i].e;
			cnt++;
		}
	}

	cout << cnt << '\n';
	return 0;
}
