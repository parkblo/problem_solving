#include <iostream>
using namespace std;

int main()
{
  int a,ans=1;
  cin >> a;
  for (int i=1; i<=a; i++) ans *= 2;
  cout << ans;
}
