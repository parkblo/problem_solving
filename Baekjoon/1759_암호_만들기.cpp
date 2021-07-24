#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> cv;
vector<char> poutv;
bool visited[16];
bool flag;

bool isVowelExist(vector<char> vec)
{
	for (int i=0;i<L;i++)
	{
		if (vec[i] == 'a' || vec[i] == 'e' ||
			vec[i] == 'i' || vec[i] == 'o' ||
			vec[i] == 'u') return true;
	}
	return false;
}

bool isConsonantsExist(vector<char> vec)
{
	int cnt=0;
	for (int i=0;i<L;i++)
	{
		if (vec[i]>='a' && vec[i]<='z'){
			if (vec[i] != 'a' && vec[i] != 'e' &&
			vec[i] != 'i' && vec[i] != 'o' &&
			vec[i] != 'u') cnt++;
		}
		
		if (cnt >= 2) return true;
	}
	
	return false;
}

void dfs(int cnt,int curr)
{
	if (cnt == L){
		
		flag = false;
		
		for (int i=1; i<L; i++)
		{
			if (poutv[i-1] > poutv[i]) flag = true;
		}
		
		if (flag == false && isVowelExist(poutv) && isConsonantsExist(poutv)){
			for (int i=0; i<L; i++){
				cout << poutv[i];
			}
			cout << '\n';
		}
		
		return;
	}
	
	for (int i=curr; i<C; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			poutv[cnt] = cv[i];
			dfs(cnt+1, i);
			visited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	char ctmp;
	cin >> L >> C;
	poutv.resize(L+1);
	
	for (int i=0;i<C;i++)
	{
		cin >> ctmp;
		cv.push_back(ctmp);
	}
	sort(cv.begin(), cv.end());
	dfs(0,0);
}
