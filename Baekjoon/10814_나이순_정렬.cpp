#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Acc{
	int age,idx;
	string name;
};

vector<Acc> v;
int n;

bool compare(struct Acc &a, struct Acc &b)
{
	if (a.age == b.age) return a.idx < b.idx;
	return a.age < b.age;
}

int main()
{
	cin >> n;

	for (int i=0; i<n; i++)
	{
		int tmp; string stmp;
		cin >> tmp >> stmp;
		v.push_back({tmp,i,stmp});
	}

	sort(v.begin(),v.end(),compare);

	for (int i=0; i<n; i++)
		cout << v[i].age << ' ' << v[i].name << '\n';

	return 0;
}
