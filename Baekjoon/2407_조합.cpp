#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string combi[101][101];

string numAdd(string s1, string s2)
{
	int sum=0;
	string ret = "";

	while(!s1.empty() || !s2.empty() || sum)
	{
		if (!s1.empty())
		{
			sum += s1.back() - '0';
			s1.pop_back();
		}
		if (!s2.empty())
		{
			sum += s2.back() - '0';
			s2.pop_back();
		}
		ret += (sum%10)+'0';
		sum /= 10;
	}

	reverse(ret.begin(),ret.end());
	return ret;
}

string pascalCombination(int n, int r)
{
	if (n == r || r == 0)
		return "1";

	string &cache = combi[n][r];

	if (cache != "")
		return cache;
	
	return cache = numAdd(pascalCombination(n-1, r-1),pascalCombination(n-1, r));
}

int main()
{
	int n, m;

	cin >> n >> m;
	cout << pascalCombination(n, m);

	return 0;
}
