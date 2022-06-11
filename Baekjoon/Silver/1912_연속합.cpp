#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 벡터 vsrc => 사용자에게 입력받은 수 보관 (원래 배열)
// 벡터 vsum => 해당 i까지의 합

// 1. 값 입력받기
// 2. i=0일 경우 자신이 vsum값이 된다.
// 3. i=1일 경우 vsum[0]+vsrc[1]가 된다.
// 4. i=2일 경우 vsum[1]+vsrc[2]가 된다.
// N. i+N일 경우 vsum[N-1] + vsrc[N]가 된다.

// vsum[N-1] + vsrc[N]과 vsrc[N]을 비교하여 더 큰 값을 가져간다
// 왜 why : 음수가 더해져서 값이 죽었을 경우에는 vsum값을 이어올 필요가 없음

int main()
{
	int sum=0,ret;
	int n;
	vector<int> vsrc;
	vector<int> vsum;
	
	cin >> n;
	vsrc.resize(n);
	vsum.resize(n);
	
	for (int i=0; i<n; i++)
		cin>>vsrc[i];
	
	vsum[0] = vsrc[0];
	ret = vsrc[0];
	
	for (int i=1; i<n; i++)
	{
		vsum[i] = max(vsum[i-1]+vsrc[i], vsrc[i]);
		ret = max(vsum[i],ret);
	}
	
	cout << ret;
	return 0;
	
}
