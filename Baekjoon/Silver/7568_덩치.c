#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

// 둘다 높으면 그 사람을 앞서는 것임
// 키나 몸무게 둘중 하나도 상대가 높으면 동률

// Function 1. canBeat 수 설정하기
// Function 2. canBeat 수대로 순위 설정하기
//		이전 최대값보다 작다는 하에 가장 큰, 그리고 동률인 사람을 구해
//		같은 사람 모두에게 랭크를 주고 사람 수만큼 랭크에 추가, 최대값 갱신하고 다음으로 넘어가

// 위와 같이 복잡하게 생각할 필요가 없었음

struct bodyProfile{
	int height;
	int weight;
	int canBeat;
	int rank;
};

void compareBodiesAndGiveCanBeat(struct bodyProfile *bp,int N)
{
	int i,o;
	for(i=0;i<N;i++)
	{
		for(o=0;o<N;o++)
		{
			if(bp[i].height<bp[o].height&&bp[i].weight<bp[o].weight)
				bp[i].canBeat++;
		}
	}
}

void compareCanBeatAndGiveRank(struct bodyProfile *bp,int N) //불필요, 그냥 기록으로 남겨둠
{
	int givenRank=1;
	int currentMax=-1;
	int turnMax=-1;
	int i,o,samePerson;
	
	for(i=0;i<N;i++){
		samePerson = -1;
		
		for(o=0;o<N;o++){
			if (bp[i].canBeat==bp[o].canBeat){
				samePerson++;
			}
		}
	}
}

void initCanBeat(struct bodyProfile *bp,int N)
{
	int i;
	for(i=0;i<N;i++){
		bp[i].canBeat = 0;
		bp[i].rank = -1;
	}
}

int main()
{
	int i,N;
	int canBeat;
	struct bodyProfile *bp;
	
	scanf("%d",&N);
	bp = (struct bodyProfile *)malloc(sizeof(struct bodyProfile)*N);
	for(i=0;i<N;i++)
	{
		scanf("%d %d",&bp[i].weight,&bp[i].height);
		initCanBeat(bp,N);
	}
	compareBodiesAndGiveCanBeat(bp,N);
	
	for(i=0;i<N;i++)
		printf("%d ",(bp[i].canBeat)+1);
}
