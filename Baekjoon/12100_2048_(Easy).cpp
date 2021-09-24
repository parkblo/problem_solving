// 아직 해결중인 문제입니다.

#include <vector>
#include <iostream>
using namespace std;

int N;
int maxBlock=0;
const int da[4] = {0,0,-1,1};
const int db[4] = {-1,1,0,0};
// left, right, up, down

bool isValidNumber(int a, int b, int dir)
{
	if (a<0 || b<0 || a>=N || b>=N)
		return false;
	
	int nextA = a + da[dir];
	int nextB = b + db[dir];

	if (nextA<0 || nextB<0 || nextA>=N || nextB>=N)
		return false;

	return true;
}

vector<vector<int>> play2048(vector<vector<int> > v, int dir)
{
	bool vis[21][21] = {false,};

	// ADD
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			if (isValidNumber(i,j,dir))
			{
				int nextA = i + da[dir];
				int nextB = j + db[dir];

				while (1)
				{
					if (nextA<0 || nextB<0 || nextA>=N || nextB>=N)
						break;
					
					if (vis[nextA][nextB] == true)
						break;

					if (v[i][j] == 0)
						break;

					if (v[nextA][nextB] == v[i][j])
					{
						v[nextA][nextB] = v[i][j] * 2;
						v[i][j] = 0;
						//vis[nextA][nextB] = true;
						break;
					}

					if (v[nextA][nextB] > 0)
						break;

					nextA += da[dir];
					nextB += db[dir];
				}
			}
		}
	}

	// PUSH TO BORDER
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			if (isValidNumber(i,j,dir))
			{
				int nextA = i + da[dir];
				int nextB = j + db[dir];

				while (v[nextA][nextB] == 0)
				{
					int prevA = nextA -= da[dir];
					int prevB = nextB -= db[dir];
					v[nextA][nextB] = v[prevA][prevB];
					v[prevA][prevB] = 0;

					nextA += da[dir];
					nextB += db[dir];
					
					if (nextA<0 || nextB<0 || nextA>=N || nextB>=N)
						break;
				}
			}
		}
	}

	return v;

	// 두번 합쳐지는 경우가 없이 하기 위해 둘로 과정을 나눴으나..
	// 높은 확률로 아닐 것 같음 (시간초과 유발할것같기도)
}

int findBiggestNum(vector<vector<int> > v)
{
	int ret=0;
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			if (ret < v[i][j])
				ret = v[i][j];
		}
	}

	return ret;
}

void dfs(vector<vector<int> > v, int dir, int cnt)
{
	if (cnt == 5)
	{
		int currBiggest = findBiggestNum(v);

		if(maxBlock < currBiggest)
			maxBlock = currBiggest;
		
		return;
	}

	v = play2048(v, dir);

	for (int i=0; i<4; i++)
		dfs(v,i,cnt+1);
}

int main()
{
	cin >> N;
	vector<vector<int> > v(N, vector<int>(N,0));

	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			cin >> v[i][j];

	for (int i=0; i<4; i++)
		dfs(v,i,0);

	cout << maxBlock << '\n';
	return 0;
}
