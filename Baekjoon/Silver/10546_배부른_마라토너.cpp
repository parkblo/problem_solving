#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	unordered_map<string,int> um;
	int n;

	cin >> n;

	for (int i=0; i<n; i++)
	{
		string stmp;
		cin >> stmp;
		if (um.count(stmp) > 0)
			um[stmp]++;
		else
			um[stmp] = 1;
	}

	for (int i=0; i<n-1; i++)
	{
		string stmp;
		cin >> stmp;
		um[stmp]--;
	}

	for (auto elem : um)
	{
		if (elem.second > 0)
		{
			cout << elem.first << '\n';
			return 0;
		}
	}

	return 0;
}
