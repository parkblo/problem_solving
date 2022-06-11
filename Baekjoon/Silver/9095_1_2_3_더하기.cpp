#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T,a;
	vector<int> vec(11);
	cin >> T;
	
	vec[1] = 1; // 1
	vec[2] = 2; // 1+1, 2
	vec[3] = 4; // 1+1+1, 2+1, 1+2, 3
	
	for (int i=4; i<=10; i++)
		vec[i] = vec[i-3] + vec[i-2] + vec[i-1];
	
	for (int i=0; i<T; i++)
	{
		cin >> a;
		cout << vec[a] << endl;
	}
}
