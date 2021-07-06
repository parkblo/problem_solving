#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int calcurateDiff (vector<int> vec)
{
	int ret=0;
	int tmp;
	
	for (int i=1;i<n;i++)
	{
		tmp = vec[i-1] - vec[i];
		
		if (tmp<0) // 절대값
			tmp = -tmp;
		
		ret += tmp;
	}
	
	return ret;
}

int findDiffMax (vector<int> vec)
{
	int ret = 0;
	
	while (next_permutation(vec.begin(), vec.end()))
	{
		ret = max(ret,calcurateDiff(vec));
	}
	
	return ret;
}

int main()
{
	vector<int> vec;
	cin >> n;
	vec.resize(n);
	
	for (int i=0;i<n;i++)
	{
		cin >> vec[i];
	}
	
	sort(vec.begin(),vec.end());
	cout << findDiffMax(vec);
	return 0;
}
