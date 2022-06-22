#include <iostream>
using namespace std;

int main()
{
	char c;
	int jh=0,doc=0;
	while (1){
		cin >> c;
		if (c == 'a') jh++;
		else break;
	}
	while (1){
		cin >> c;
		if (c == 'a') doc++;
		else break;
	}

	if (jh >= doc) cout << "go\n";
	else cout << "no\n";

	return 0;
}
