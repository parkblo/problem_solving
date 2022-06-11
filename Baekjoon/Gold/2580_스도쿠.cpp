#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

int board[9][9];
bool flag=false;

void finishBoard(){
	for (int i=0; i<9; i++){
		for (int j=0; j<9; j++){
			cout<<board[i][j]<<' ';
		}
		cout<<'\n';
	}
	flag = true;
}

bool checkRow(int a, int b)
{
	int cnt=0;
	for (int i=0;i<9;i++){
		if (board[a][i] == board[a][b]) cnt++;
	}

	if (cnt>=2) return false;
	return true;
}

bool checkCol(int a, int b)
{
	int cnt=0;
	for (int i=0;i<9;i++){
		if (board[i][b] == board[a][b]) cnt++;
	}

	if (cnt>=2) return false;
	return true;
}

bool checkSquare(int a, int b)
{
	int cnt=0;
	int startA, startB;

	if (a>=0 && a<3)
		startA = 0;
	else if (a>=3 && a<6)
		startA = 3;
	else if (a>=6 && a<9)
		startA = 6;

	if (b>=0 && b<3)
		startB = 0;
	else if (b>=3 && b<6)
		startB = 3;
	else if (b>=6 && b<9)
		startB = 6;

	for (int i=startA; i<startA+3; i++){
		for (int j=startB; j<startB+3; j++){
			if (board[i][j] == board[a][b]) cnt++;
		}
	}

	if (cnt>=2) return false;
	return true;
}

void DFS(int curr)
{
	if (flag) return;

	// curr 좌표 환산
	int currA = curr / 9;
	int currB = curr % 9;

	// 모든 숫자가 정해졌을 경우
	if (curr == 81){
		finishBoard();
		return;
	}

	// 0이 아닌 칸은 채우지 않는다
	if (board[currA][currB] != 0)
	{
		DFS(curr+1);
		return;
	}

	for (int i=1;i<=9;i++){
		board[currA][currB] = i;
		// 스도쿠의 규칙에 맞는지 확인
		if (checkRow(currA,currB) && checkCol(currA,currB) && checkSquare(currA,currB))
			DFS(curr+1);
		board[currA][currB] = 0;
	}
}

int main()
{
	// input
	for (int i=0; i<9; i++){
		for (int j=0; j<9; j++){
			scanf("%1d", &board[i][j]);
		}
	}

	DFS(0);

	return 0;
}
