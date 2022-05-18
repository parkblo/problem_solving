#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, arr[8], res[8];
bool chk[8] = { false };

void func(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", res[i]);
		printf("\n");
		return;
	}
	int xx = 0;
	for (int i = 0; i < n; i++) {
		if (!chk[i] && arr[i] != xx) {
			res[cnt] = arr[i];
			xx = res[cnt];
			chk[i] = true;
			func(cnt + 1);
			chk[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	func(0);
}
