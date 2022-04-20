#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int C,N,L,ar[1001];
	for(scanf("%d",&C); C--;)
	{
		scanf("%d %d",&N,&L);
		for (int i=1; i<=N; i++)
		{
			scanf("%d",&ar[i]);
			ar[i] += ar[i-1];
		}
		
		double ret = 1e9;	

		for (int i=0; i<=N; i++){
			for (int j=i+L; j<=N; j++){
				double curr = (double)(ar[j] - ar[i]) / (j-i);
				ret = min(curr,ret);
			}
		}
		printf("%.12lf\n",ret);
	}
	return 0;
}
