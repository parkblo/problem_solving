#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool groupChecker(string s)
{
	bool alp[26] = {false,};

	for (int i=0; i<s.size(); i++)
	{
		if (alp[s[i]-'a'])
		{
			return false;
		}
		else
		{
			alp[s[i]-'a'] = true;

			while (s[i] == s[i+1])
			{
				i++;
			}
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int ret=0;
	for (int i=0; i<N; i++)
	{
		string stmp;
		cin >> stmp;

		if (groupChecker(stmp)) ret++;
	}

	cout << ret << '\n';
	return 0;
}
