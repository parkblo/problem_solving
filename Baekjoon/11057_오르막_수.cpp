#include <iostream>
#define MODULAR 10007
using namespace std;

int main()
{
	int n,dp[1001];
	int ar[10]={10,9,8,7,6,5,4,3,2,1};
	
	cin >> n;
	
	dp[1] = 10;
	dp[2] = 55;
	
	for (int i=3; i<=n; i++){
		int val = 0;
		for (int j=0; j<10; j++){
			int sum = 0;
			for (int k=j; k<10; k++){
				sum += ar[k];
			}
			ar[j] = sum;
			ar[j] %= MODULAR;
			val += sum;
		}
		dp[i] = val % MODULAR;
	}
	cout << dp[n];
	return 0;
}
