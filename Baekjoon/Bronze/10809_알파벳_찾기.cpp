#include <iostream>
#include <vector>
#include <string>
using namespace std;

int findChar(char c, string& str)
{
	for (int i=0; i<str.size(); i++)
	{
		if (c==str[i]){
			return i;
		}
	}
	return -1;
}

int main()
{
	char alp ='a';
	string S;
	cin >> S;
	
	while (alp<='z')
	{
		cout << findChar(alp,S) << ' ';
		alp++;
	}
}
