#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct pos{int a; int b; int dist;};

// UP LEFT RIGHT DOWN
const int dy[4] = {-1,0,0,1};
const int dx[4] = {0,-1,1,0};

vector<vector<int>> space;
vector<pos> preyVec;
int N, currDist, sharkSize = 2, sharkPreyStack = 0;
pos sharkPS, preyPS;
queue<pos> que;
bool visited[21][21] = {false,};
bool flag = false;
int retDist = 0;

void debug()
{
	cout << "// sharkSize:" << sharkSize << ' ' << "currDist: " << currDist << '\n'; 
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			cout << space[i][j] << visited[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

bool comp(pos a, pos b)
{
	if (a.a < b.a)
		return true;
	else if (a.a == b.a && a.b < b.b)
		return true;
	else
		return false;
}

void clearVisited()
{
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			visited[i][j] = false;
		}
	}
}

bool isAllTrueVisited()
{
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			if (visited[i][j] == false) return false;
		}
	}
	return true;
}

int BFS(pos sharkPS)
{
	// return
	// -1 : 엄마 상어 호출 필요
	// 1 : 먹이를 먹을 수 있음

	currDist = sharkPS.dist;
	que.push({sharkPS.a, sharkPS.b, sharkPS.dist});
	while (!que.empty())
	{
		// 더이상 방문 할 곳이 없다면
		if (isAllTrueVisited())
		{
			if (!preyVec.empty()) return 1;
			else return -1;
		}

		if (visited[que.front().a][que.front().b] == true)
		{
			que.pop();
			continue;
		} 

		for (int i=0; i<4; i++)
		{
			int nextA = que.front().a + dy[i];
			int nextB = que.front().b + dx[i];
			int nextDist = que.front().dist + 1;
			// 범위 내에 있는지 확인
			if (nextA<0 || nextB<0 || nextA>=N || nextB>=N)
				continue;

			// 자신보다 큰 먹이는 지나갈 수 없음
			if (space[nextA][nextB] > sharkSize)
				continue;

			// 먹이를 먹을 수 있는 경우
			if (space[nextA][nextB] >= 1 && space[nextA][nextB] < sharkSize){
				// 기존 먹이후보 보다 거리가 더 먼 경우
				if (!preyVec.empty() && preyVec[0].dist < nextDist) {
					return 1;
				}
				preyVec.push_back({nextA, nextB, nextDist});
			}
			que.push({nextA, nextB, nextDist});
		}
		visited[que.front().a][que.front().b] = true;
		//debug();
		que.pop();
	}

	if (!preyVec.empty()) return 1;
	else return -1;
}

int main()
{
	cin >> N;
	space.resize(N,vector<int>(N));

	// input
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			cin >> space[i][j];
			if (space[i][j] == 9){
				sharkPS = {i, j, 0};
				space[i][j] = 0;
			}
		}
	}

	while (1)
	{
		int ret = BFS(sharkPS);

		if (ret == -1) break;
		else if (ret == 1){
			sort(preyVec.begin(),preyVec.end(),comp);
			preyPS = {preyVec[0].a, preyVec[0].b, preyVec[0].dist};
			retDist = preyPS.dist;
			sharkPS = {preyPS.a, preyPS.b, preyPS.dist};
			space[preyPS.a][preyPS.b] = 0;
			sharkPreyStack++;
			// 전체 초기화
			while(!que.empty()) que.pop();
			clearVisited();
			preyVec.clear();
		}

		// 상어크기 성장
		if (sharkPreyStack >= sharkSize)
		{
			sharkPreyStack = 0;
			sharkSize++;
		}
	}
	cout << retDist;
}
