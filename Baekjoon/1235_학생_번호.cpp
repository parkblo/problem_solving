#include <string>
#include <iostream>
using namespace std;

int n;
string s[1001];
string st[1001];

void reverseString()
{
	for (int i=0; i<n; i++)
	{
		string stmp = "";
		for (int j=s[i].size()-1; j>=0 ;j--)
		{
			stmp += s[i][j];
		}
		s[i] = stmp;
	}
}

int solve()
{
	bool flag;

	for (int i=0; i<s[0].size(); i++)
	{
		for (int j=0;j<n;j++)
		{
			st[j] += s[j][i];
		}

		
		flag = false;
		for (int k=0; k<n; k++)
		{
			for (int p=k+1; p<n; p++)
			{
				if (st[k] == st[p])
				{flag = true; break;}
			}
			if (flag == true) break;
		}
		if (flag == false) return i+1;
	}

	return n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> s[i];

	reverseString();

	cout << solve();
	return 0;
}
