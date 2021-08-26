#include <iostream>
using namespace std;

int n;
int io[100001]; //inorder
int po[100001]; //postorder
int idx[100001];

void solve(int inStart, int inEnd, int postStart, int postEnd)
{
	if (inStart > inEnd || postStart >> postEnd)
		return;
	
	int root = po[postEnd];
	int left = idx[root] - inStart;
	int right = inEnd - idx[root];
	cout << root << " ";

	solve(inStart, idx[root]-1, postStart, postStart+left-1);
	solve(idx[root]+1, inEnd, postStart+left, postEnd-1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i=0; i<n; i++)
	{
		cin >> io[i];
		idx[io[i]] = i;
	}

	for (int i=0; i<n; i++)
		cin >> po[i];

	solve(0,n-1,0,n-1);
	cout << "\n";
	return 0;
}
