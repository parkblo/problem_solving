#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a,b;
vector<int> va;
bool vis[15] = {false,};
int ans=-1;

void dfs(int curr, int depth)
{
	if (depth >= va.size())
	{
		if(curr <= b){
			ans = max(ans,curr);
		}
		return;
	}
	
	for (int i=0; i<va.size(); i++)
	{
		if (vis[i]) continue;
		if (depth==0 && va[i]==0) continue;
		
		vis[i] = true;
		dfs(curr*10+va[i],depth+1);
		vis[i] = false;
	}

	return;
}


int main()
{
    cin >> a >> b;
	
    while (a>0)
    {
        va.push_back(a%10);
        a /= 10;
    }
	
	dfs(0,0);

	if (ans == -1) cout << -1 << '\n';
	else cout << ans << '\n';

    return 0;
}
