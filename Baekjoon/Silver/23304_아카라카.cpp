#include <iostream>
#include <string>
using namespace std;

bool akaraka(string s)
{
	int len = s.length();

	if (len <= 1) return true;

	for (int i=0; i<len/2; i++)
	{
		if (s[i] != s[len-1-i]) return false;
	}

	string pre;
	for (int i=0; i<len/2; i++)
	{
		pre += s[i];
	}

	if (!akaraka(pre)) return false;

	return true;
}

int main()
{
	string str;
	cin >> str;

	if (akaraka(str)) cout << "AKARAKA\n";
	else cout << "IPSELENTI\n";

	return 0;
}
