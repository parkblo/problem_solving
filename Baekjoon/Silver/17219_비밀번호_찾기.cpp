#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  map<string, string> m;
  int N,M;

  cin >> N >> M;
  for (int i=0; i<N; i++){
    string s1,s2;
    cin >> s1 >> s2;
    m[s1] = s2;
  }

  for (int i=0; i<M; i++){
    string s1;
    cin >> s1;
    cout << m[s1] << '\n';
  }

  return 0;
}
