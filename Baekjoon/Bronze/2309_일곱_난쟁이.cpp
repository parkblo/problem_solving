#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// input: int 9개
// output: 조건하 선택된 int 7개 (오름차순)
// 조건: 7 of 9
// 		sum == 100

// 7개를 선택하면 되므로 9개의 합을 구하고 두 키를 빼서 100이 되는 경우 생각

int compare(int a,int b)
{
	return b>a;
}

int main()
{
	int vi,vj;
	int sum=0;
	vector<int> vec;
	vec.resize(9);
	
	for (int i=0;i<9;i++)
	{
		cin >> vec[i];
		sum += vec[i];
	}
	
	for (int i=1;i<9;i++){
		for (int j=0;j<i;j++){
			if (sum-(vec[i]+vec[j])==100){
				vi = i; vj = j;
			}
		}
	}
	
	vec.erase(vec.begin()+vi);
	vec.erase(vec.begin()+vj);
	
	sort(vec.begin(),vec.end(),compare);
	
	for(int i=0;i<7;i++)
	{
		cout << vec[i] << endl;
	}
}
