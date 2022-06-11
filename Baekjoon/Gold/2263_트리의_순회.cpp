#include <iostream>
using namespace std;

int n;
int io[100001]; //inorder
int po[100001]; //postorder
int idx[100001]; // inorder의 해당 값이 어떤 인덱스 번호에 저장돼있는지 저장하는 배열

void solve(int inStart, int inEnd, int postStart, int postEnd)
{
	if (inStart > inEnd || postStart > postEnd)
		return;
	
	int root = po[postEnd]; // postOrder의 제일 마지막 수는 root가 됨
	int left = idx[root] - inStart; // inorder의 root가 저장된 곳을 기준으로 왼쪽, 오른쪽이 구분됨
	int right = inEnd - idx[root]; // 위 논리와 동일
	cout << root << " "; // preorder은 root 우선 출력이므로 root 출력

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
