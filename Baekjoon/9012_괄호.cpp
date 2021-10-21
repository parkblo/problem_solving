#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkVPS(string s)
{
	stack<char> st;

	for (int i=0; i<s.size(); i++)
	{
		if (s[i] == '(')
			st.push(s[i]);
		else if (s[i] == ')')
		{
			if (st.empty())
				return false;
			else
				st.pop();
		}
	}

	if (!st.empty()) return false;
	
	return true;
}

int main()
{
	stack<int> st;
	int t;
	cin >> t;

	for (int i=0; i<t; i++)
	{
		string stmp;
		cin >> stmp;

		bool flag = checkVPS(stmp);

		if (flag) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}
