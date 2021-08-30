#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}

int pr(char c)
{
	if (c == '(') return 0;
	else if (c=='+'||c=='-') return 1;
	else if (c=='*'||c=='/') return 2;
	else {cout << "ERROR\n"; return -1;}
}

int main()
{
	stack<char> s;
	string str;
	cin >> str;

	for (int i=0; i<str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			cout << str[i];
		else if (str[i] == '(') s.push(str[i]);
		else if (str[i] == ')')
		{
			while (!s.empty() && s.top()!='(')
			{
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else if (isOperator(str[i]))
		{
			while (!s.empty() && pr(s.top()) >= pr(str[i]))
			{
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}

	return 0;
}
