#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Sub{
	int start,end;
}sub;

bool compare(sub &a, sub &b)
{
	return a.start < b.start;
}

int main()
{
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<sub> v;

	int n;
	cin >> n;

	for (int i=0; i<n; i++)
	{
		int s,e;
		cin >> s >> e;
		v.push_back({s,e});
	}

	sort(v.begin(),v.end(),compare);
	pq.push(v[0].end);

	int ret = 0;
	
	for (int i=1; i<n; i++)
	{
		if (v[i].start >= pq.top())
			pq.pop();
		
		pq.push(v[i].end);
	}

	cout << pq.size() << '\n';
	return 0;
}
