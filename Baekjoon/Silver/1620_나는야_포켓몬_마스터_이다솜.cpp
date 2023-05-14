#include <iostream>
#include <map>
#include <string>
using namespace std;


int main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);

  int n,m;
  map<string, int> m1;
  map<int, string> m2;
  
  cin >> n >> m;
  
  for (int i=1; i<=n; i++){
    string stmp;
    cin >> stmp;
    m1[stmp] = i;
    m2[i] = stmp;
  }

  for (int i=0; i<m; i++){
    string stmp;
    int itmp;
    cin >> stmp;
    if (stmp[0] >= '0' && stmp[0] <= '9'){
      itmp = stoi(stmp);
      cout << m2[itmp] << '\n';
    }
    else {
      cout << m1[stmp] << '\n';
    }
  }
  
  return 0;
}
