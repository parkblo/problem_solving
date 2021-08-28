// 알아야 하는 지식
// 1. 피보나치를 행렬로 구하는 방법 + (행렬의 곱셈법)
// 2. 제곱을 O(logK)로 구하는 방법 (boj 1629)

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<long long>> matrix;
const long long mod = 1000000007;

matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size(); //*
    matrix c(n, vector<long long>(n));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j]; //* c[][]의 초기값은 0으로 설정되는가?
            }
            c[i][j] %= mod;
        }
    }
    return c;
}

int main() {
    long long n;

    cin >> n;

    matrix ans = {{1, 0}, {0, 1}};
    matrix a = {{1, 1}, {1, 0}};

    while (n > 0) {
        if (n % 2 == 1) {
            ans = ans * a;
        }
        a = a * a;
        n /= 2;
    }

    cout << ans[0][1] << '\n';

    return 0;
}
