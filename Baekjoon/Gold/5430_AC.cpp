#include <queue>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool rvs = false;
bool errorCheck = false;
deque<int> dq;
int t,n;
string p,stmp,ret;

void inputNum(string s)
{	
	int num=0;
	bool numAdded = false;

	for (int i=0; i<s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num *= 10;
			num += s[i]-'0';
			numAdded = true;
		}
		else
		{
			if (numAdded)
			{
				dq.push_back(num);
				num = 0;
				numAdded = false;
			}
		}
	}
}

void solve(string s)
{
	for (int i=0; i<s.size(); i++)
	{
		if (s[i] == 'R')
		{
			if (rvs)
				rvs = false;
			else
				rvs = true;
		}
		else if (s[i] == 'D')
		{
			if (dq.empty()){
				errorCheck = true;
				return;
			}

			if (!rvs)
			{
				dq.pop_front();
			}
			else
			{
				dq.pop_back();
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;

	for (int i=0; i<t; i++)
	{
		deque<int> emptydq;
		dq = emptydq;
		rvs = false;
		errorCheck = false;
		ret = "";

		cin >> p;
		cin >> n;
		cin >> stmp;

		inputNum(stmp);
		solve(p);

		if (errorCheck)
			cout << "error" << '\n';
		else
		{
			if (rvs)
				reverse(dq.begin(),dq.end());

			cout << '[';
			for (int j=0; j<dq.size(); j++)
			{
				if (j == dq.size()-1)
					cout << dq[j];
				else
					cout << dq[j] << ',';
			}
			cout << "]\n";
		}
	}
}
