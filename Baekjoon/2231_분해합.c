#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main()
{
	int num;
	int sum;
	int tmpNum;
	int N;
	
	scanf("%d",&N);
	
	for (num=1;num<N;num++)
	{
		sum=0;
		sum += num;
		tmpNum = num;
		
		do{
			sum = sum + (tmpNum%10);
			tmpNum /= 10;
		} while((tmpNum%10)>0);
		
		if (sum==N){
			printf("%d",num);
			return 0;
		}
	}
	
	printf("0");
	return 0;
}
