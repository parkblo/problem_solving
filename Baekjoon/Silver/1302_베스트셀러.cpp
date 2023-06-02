#include <iostream>
#include <map>
using namespace std;

int main()
{
  map<string,int> m;
  int maxval=0,N;
  string stmp,maxstr;

  cin >> N;

  for (int i=0; i<N; i++){
    cin >> stmp;
    m[stmp]++;
    if (m[stmp] > maxval){
      maxval=m[stmp];
      maxstr=stmp;
    }
    else if (m[stmp] == maxval){
      if (maxstr > stmp) maxstr = stmp;
    }
  }

  cout << maxstr;
  return 0;
}
