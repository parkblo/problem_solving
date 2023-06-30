#include <iostream>
#include <vector>
using namespace std;

int N, maxv=0;

void f(int cnt, vector<int> v, vector<int> ans)
{
  int correct = 0;
  
  // 답과 대조
  for (int i=0; i<N; i++){
    if (ans[i] == v[i]) correct++;
  }
  if (maxv < correct) maxv = correct;

  // 밀거나 당기기 시작 전 검사
  if (cnt <= 0) return;

  // 밀기
  for (int i=0; i<N; i++){
    vector<int> pushV(N,-1);
    for (int j=0; j<N; j++){
      if (j < i) pushV[j] = v[j];
      else {
        if (j+1 < N) pushV[j+1] = v[j];
      }
    }
    f(cnt-1,pushV,ans);
  }

  // 당기기
  for (int i=0; i<N; i++){
    vector<int> pullV(N,-1);
    for (int j=0; j<N; j++){
      if (j < i) pullV[j] = v[j];
      else {
        if (j+1 < N) pullV[j] = v[j+1];
      }
    }
    f(cnt-1,pullV,ans);
  }
}

int main()
{
  int K;
  cin >> N >> K;
  vector<int> v(N,-1),ans(N,0); // -1이 같아서 정답되는거 방지로 0줬음
  
  for (int i=0; i<N; i++){
    int tmp;
    cin >> tmp;
    ans[i] = tmp;
  }

  for (int i=0; i<N; i++){
    int tmp;
    cin >> tmp;
    v[i] = tmp;
  }

  f(K,v,ans);

  cout << maxv << '\n';
  return 0;
}
