#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	vector<char> cv;
	vector<int> nv;
	int nvSize = -1;
	string str;
	bool isNum = false;

	// input
	cin >> str;
	for (int i=0; i<str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (!isNum)
			{
				isNum = true;
				nv.push_back(str[i]-'0');
				nvSize++;
				continue;
			}

			nv[nvSize] = nv[nvSize] * 10 + str[i]-'0';
		}
		else
		{
			cv.push_back(str[i]);
			isNum = false;
		}
	}

	// solve
	bool minus = false;
	for (int i=0; i<cv.size(); i++)
	{
		if (cv[i] == '-') minus = true;

		if (!minus) continue;

		if (cv[i] == '+') cv[i] = '-';
	}

	int ret = nv[0];
	for (int i=1; i<nv.size(); i++)
	{
		if (cv[i-1] == '-')
		{
			ret -= nv[i];
		}
		else
		{
			ret += nv[i];
		}
	}

	cout << ret << '\n';
	return 0;
}
