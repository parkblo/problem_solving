#include <iostream>
#include <string>
using namespace std;

int main()
{
	string X;
	int cnt = 0, Y = 0;
	
	cin >> X;

	// 한자리수인 경우 (cnt==0)
	if (X.length() < 2){
		cout << cnt << '\n';

		Y = X[0] - '0';

		if (Y<=2) {
			cout << "NO";
			return 0;
		}
		if (Y%3==0) cout << "YES";
		else cout << "NO";
		return 0;
	}

	// 변환 한번 수행 (큰수로 인한 문제 해소)
	cnt++;
	for (int i=0; i<X.length(); i++){
		Y += X[i] - '0';
	}
	// 추가 변환 수행
	while (Y >= 10){
		cnt++;
		int tmp=0;
		while (Y > 0){
			tmp += Y%10;
			Y /= 10;
		}
		Y = tmp;
	}
	// 결과 출력
	cout << cnt << '\n';
	if (Y<=2) {
			cout << "NO";
			return 0;
	}
	if (Y%3==0) cout << "YES";
	else cout << "NO";

	return 0;
}
