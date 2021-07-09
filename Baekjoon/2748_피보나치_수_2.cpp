#include <iostream>
#include <vector>
using namespace std;

vector<long long> cache(100,-1);

long long fibo(int n)
{
	long long &ret = cache[n];
	
	if (n==0)
		return ret = 0;
	if (n==1)
		return ret = 1;
	
	if (ret != -1)
		return ret;
	else
		return ret = fibo(n-2)+fibo(n-1);
}

int main()
{
	int n;
	cin >> n;
	cout << fibo(n);
}
