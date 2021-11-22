#include <iostream>
#include <stack>
using namespace std;

typedef struct Sub{
	int score, time;
}sub;

stack<sub> s;

int main()
{
	int n, ret=0;
	cin >> n;

	for (int i=0; i<n; i++)
	{
		int num, A, T;
		cin >> num;

		if (num == 1)
		{
			cin >> A >> T;
			s.push({A,T});
		}

		if (s.empty()) continue;

		s.top().time--;

		if (s.top().time <= 0)
		{
			ret += s.top().score;
			s.pop();
		}
	}
	
	cout << ret << '\n';
	return 0;
}
