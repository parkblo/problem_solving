#include <iostream>
#include <string>
using namespace std;

// 1. = 발견된 경우 c, s, z, dz
// 2. - 발견된 경우 c, d
// 3. j 발견된 경우 l, n

int main()
{
	string str;
	cin >> str;
	int ret = str.size();

	for (int i=0; i<str.size(); i++)
	{
		if (str[i] == '=' && i-1>=0)
		{
			if (str[i-1] == 'c') ret--;
			else if (str[i-1] == 's') ret--;
			else if (str[i-1] == 'z'){
				ret--;
				if (i-2>=0){
					if (str[i-2] == 'd') ret--;
				}
			}
		}
		else if (str[i] == '-' && i-1>=0){
			if (str[i-1] == 'c') ret--;
			else if (str[i-1] == 'd') ret--;
		}
		else if (str[i] == 'j' && i-1>=0){
			if (str[i-1] == 'l') ret--;
			else if (str[i-1] == 'n') ret--;
		}
	}

	cout << ret << endl;
}
