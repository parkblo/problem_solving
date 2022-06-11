#include <iostream>
#include <vector>
using namespace std;

int N;
int pl=0,mi=0,mu=0,di=0;
int minRet = 2000000000;
int maxRet = -2000000000;

vector<int> num;
vector<char> op;
bool vis[10000] ={false,};

void solve(int curr, int cnt)
{
	if (cnt == N){
		if (minRet > curr) minRet = curr;
		if (maxRet < curr) maxRet = curr;
		return;
	}
	
	for (int i=0; i<op.size(); i++)
	{
		if (vis[i] == true)
			continue;

		vis[i] = true;
		if (op[i] == '+'){
			solve(curr+num[cnt] ,cnt+1);
		}
		else if (op[i] == '-'){
			solve(curr-num[cnt] ,cnt+1);
		}
		else if (op[i] == '*'){
			solve(curr*num[cnt] ,cnt+1);
		}
		else if (op[i] == '/'){
			solve(curr/num[cnt] ,cnt+1);
		}
		vis[i] = false;
	}
}

int main()
{
	cin >> N;
	for (int i=0; i<N; i++)
	{
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	cin >> pl >> mi >> mu >> di;

	for(int i=0; i<pl; i++)
		op.push_back('+');
	for(int i=0; i<mi; i++)
		op.push_back('-');
	for(int i=0; i<mu; i++)
		op.push_back('*');
	for(int i=0; i<di; i++)
		op.push_back('/');

	solve(num[0],1);

	cout << maxRet << '\n' << minRet << '\n';
	return 0;
}
