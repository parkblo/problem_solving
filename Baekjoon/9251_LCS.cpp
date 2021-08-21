#include <iostream>
#include <string>
using namespace std;

int Max(int a, int b) {return a > b ? a : b;}

int main()
{
	string s1,s2;
	int ans[1010][1010];

	cin >> s1;
	cin >> s2;
	
	for (int i=0; i<=s1.length(); i++)
		for (int j=0; j<=s2.length(); j++)
			ans[i][j] = 0;
	
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
	return 0;
}
