#include <iostream>
using namespace std;

int ret = 0;
int N;
bool visited[15][15]={false,};

bool isAvailable(int a, int b)
{
	// 같은 열 확인
	for (int i=1; i<=N; i++){
		if (visited[i][b] == true)
			return false;
	}

	// 대각선 확인
	for (int i=a, j=b; i<=N && j<=N; i++, j++){
		if (visited[i][j] == true)
			return false;
	}
	for (int i=a, j=b; i<=N && j>=1; i++, j--){
		if (visited[i][j] == true)
			return false;
	}
	for (int i=a, j=b; i>=1 && j<=N; i--, j++){
		if (visited[i][j] == true)
			return false;
	}
	for (int i=a, j=b; i>=1 && j>=1; i--, j--){
		if (visited[i][j] == true)
			return false;
	}

	return true;
}

void nQueen(int a, int b)
{
	if (isAvailable(a, b) == false) return;
	if (a == N) {ret++; return;}

	for (int i=1; i<=N; i++)
	{
		visited[a][b] = true;
		nQueen(a+1,i);
		visited[a][b] = false;
	}
}

int main()
{
	cin >> N;

	for (int i=1; i<=N; i++)
		nQueen(1,i);

	cout << ret;
	return 0;
}
