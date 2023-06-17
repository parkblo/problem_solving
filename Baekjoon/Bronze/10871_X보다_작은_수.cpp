#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N,X;
  vector<int> ret;
  cin >> N >> X;
  for (int i=0; i<N; i++)
    {
      int tmp;
      cin >> tmp;
      if (tmp < X) ret.push_back(tmp);
    }
    for (int i=0; i<ret.size(); i++){
      cout << ret[i] << ' ';
    }
}
