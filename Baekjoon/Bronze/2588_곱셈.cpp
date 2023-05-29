#include <iostream>
using namespace std;

int main()
{
  int a,b,c;
  cin >> a >> b;
  c=b;
  while (c>0){
    cout << a*(c%10) << '\n';
    c /= 10;
  }
  cout << a*b;
  return 0;
}
