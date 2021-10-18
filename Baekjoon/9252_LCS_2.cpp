#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int Max(int a, int b) {return a > b ? a : b;}

int main()
{
	string s1,s2;
	int ans[1010][1010];

	cin >> s1;
	cin >> s2;
	
	// init
	for (int i=0; i<=s1.length(); i++)
		for (int j=0; j<=s2.length(); j++)
			ans[i][j] = 0;

	// LCS 1
	for (int i=1; i<=s1.length(); i++)
	{
		for (int j=1; j<=s2.length(); j++)
		{
			if (s1[i-1] == s2[j-1])
				ans[i][j] = ans[i-1][j-1] + 1;
			else
				ans[i][j] = Max(ans[i-1][j],ans[i][j-1]);
		}
	}

	cout << ans[s1.length()][s2.length()] << '\n';

	// LCS 2
	int ii = s1.length();
	int jj = s2.length();
	string ss;
	while (1)
	{
		if (ans[ii][jj] == 0) break;

		if (ans[ii][jj] == ans[ii-1][jj])
			ii--;
		else if (ans[ii][jj] == ans[ii][jj-1])
			jj--;
		else
		{
			ss += s1[ii-1];
			ii--; jj--;
		}
	}

	reverse(ss.begin(),ss.end());

	cout << ss << '\n';
	return 0;
}
