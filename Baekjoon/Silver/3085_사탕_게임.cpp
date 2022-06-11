#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int N;
char **arr;

int findCombo(char **arr)
{
	int ret=0;
	int combo;
	
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{
			combo = 1;
			for (int q=i+1;q<N;q++) //row row row row row row row row
			{
				if(arr[i][j] == arr[q][j])
				{
					combo++;
				}
				else
				{
					break;
				}
			}
			ret = max(ret,combo);
			
			combo = 1;
			for (int q=j+1;q<N;q++) //col col col col col col col col col col col col col
			{
				if(arr[i][j] == arr[i][q])
				{
					combo++;
				}
				else
				{
					break;
				}
			}
			ret = max(ret,combo);
		}
	}
	
	return ret;
}

int main()
{
	int ret=0;
	cin >> N;
	
	arr = (char**)malloc(sizeof(char*)*N);
	for (int i=0;i<N;i++)
		arr[i] = (char*)malloc(sizeof(char)*N);
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> arr[i][j];
	
	for (int i=0;i<N;i++) //swap 변환 arr 생성
	{
		for(int j=0;j<N;j++)
		{
			if(i+1<N)
				if(arr[i][j]!=arr[i+1][j]){
					swap(arr[i][j],arr[i+1][j]);
					ret = max(findCombo(arr),ret);
					swap(arr[i][j],arr[i+1][j]); //원상복구
				}
			
			if(j+1<N)
				if(arr[i][j]!=arr[i][j+1]){
					swap(arr[i][j],arr[i][j+1]);
					ret = max(findCombo(arr),ret);
					swap(arr[i][j],arr[i][j+1]); //원상복구
				}
		}
	}
	
	cout << ret;
	return 0;
}
