#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string WFirstStr[8] = {"WBWBWBWB", "BWBWBWBW"
						 ,"WBWBWBWB", "BWBWBWBW"
						 ,"WBWBWBWB", "BWBWBWBW"
						 ,"WBWBWBWB", "BWBWBWBW"};

string BFirstStr[8] = {"BWBWBWBW", "WBWBWBWB"
						 ,"BWBWBWBW", "WBWBWBWB"
						 ,"BWBWBWBW", "WBWBWBWB"
						 ,"BWBWBWBW", "WBWBWBWB"};

int M,N;

vector<vector<char>> slice88Board (vector<vector<char>> vec,int a,int b)
{
	vector<vector<char>> ret(8,vector<char>(8));
	
	for (int i=a,q=0; i<a+8; i++, q++)
	{
		for (int j=b,p=0; j<b+8; j++, p++)
		{
			ret[q][p] = vec[i][j];
		}
	}
	
	return ret;
}

int compareWithWFirst (vector<vector<char>> vec)
{
	int ret=0;
	
	for (int i=0;i<8;i++)
	{
		for (int j=0;j<8;j++)
		{
			if (vec[i][j] != WFirstStr[i][j]){
				ret++;
			}
		}
	}
	return ret;
}

int compareWithBFirst (vector<vector<char>> vec)
{
	int ret=0;
	
	for (int i=0;i<8;i++)
	{
		for (int j=0;j<8;j++)
		{
			if (vec[i][j] != BFirstStr[i][j]){
				ret++;
			}
		}
	}
	return ret;
}

int main()
{
	int minValue = 64;
	
	cin >> M >> N;
	vector<vector<char>> vec(M, vector<char>(N));
	vector<vector<char>> vtmp;
	
	for (int i=0; i<M ; i++)
		for (int j=0; j<N; j++)
			cin >> vec[i][j];
	
	for (int i=0;i<M;i++)
	{
		for (int j=0;j<N;j++)
		{
			if (i+8<=M && j+8<=N)
			{
				vtmp = slice88Board(vec,i,j);
				minValue = min(minValue,compareWithBFirst(vtmp));
				minValue = min(minValue,compareWithWFirst(vtmp));
			}
		}
	}
	
	cout << minValue;
	return 0;
}
