#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

// N : 카드 갯수
// M : 기준 숫자

// PLAYER
// N장의 카드 중 3개 선택, 카드 합이 M이하면서 M과 가까워야 승리
// M에 최대한 가까운 '카드 3개의 합' 구하기

// 3중포문

int main()
{
	int N,M,i,o,u;
	int *card = NULL;
	int min=300000,value,savedValue,diff;
	
	scanf("%d %d",&N,&M);
	card = (int *)malloc(sizeof(int)*N);
	
	for (i=0;i<N;i++)
	{
		scanf("%d",card+i);
	}
	
	for (i=0;i<N;i++)
	{
		for (o=0;o<N;o++)
		{
			for (u=0;u<N;u++)
			{
				if(i!=o && o!=u && i!=u)
				{
					value = *(card+i) + *(card+o) + *(card+u);
					diff = M - value;
					if (diff>=0 && diff<min)
					{
						min = diff;
						savedValue = value;
					}
				}
			}
		}
	}
	
	printf("%d",savedValue);
	
	free(card);
	return 0;
}
