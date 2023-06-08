#include <iostream>
using namespace std;

int main()
{
  int n,ans=0;
  cin >> n;
  for (int i=1; i<=n; i++) ans+=i;
  cout << ans;
}
