#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int N, ret=0;
	cin >> N;
	
	for (int i=0; i<N; i++){
		stack<char> s;
		string str;
		
		cin >> str;
		for (int j=0; j<str.length(); j++){
			if (s.empty()) s.push(str[j]);
			else if (s.top() == str[j]) s.pop();
			else s.push(str[j]);
		}

		if (s.empty()) ret++;
	}
	
	cout << ret << '\n';
	return 0;
}
