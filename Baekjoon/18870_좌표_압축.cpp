#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> vec(N);
	vector<int> cpy(N);
	
	for (int i=0; i<N; i++)
	{
		cin >> vec[i];
		cpy[i] = vec[i];
	}
	
	sort(cpy.begin(),cpy.end());
	cpy.erase(unique(cpy.begin(),cpy.end()),cpy.end());
	
	for (int i=0; i<N; i++)
	{
		cout << lower_bound(cpy.begin(), cpy.end(), vec[i]) - cpy.begin() << ' ';
	}
}
