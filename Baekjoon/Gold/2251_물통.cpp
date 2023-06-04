#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool vis[201][201][201]= {false,};
vector<int> ans;
int asize,bsize,csize;

void dfs(int a, int b, int c)
{
  if(vis[a][b][c]) return;
  else vis[a][b][c] = true;
  
  // A가 비었을 때, C에 담겨있을 수 있는 물의 양 구하기
  if (a==0){
    bool flag=false;
    // 중복 방지
    for (int i=0; i<ans.size(); i++){
      if (ans[i] == c) {
        flag = true;
        break;
      }
    }
    if (flag==false){
      ans.push_back(c);
    }
  }

  // A가 받을 수 있는 경우
  if (asize-a > 0){
    // B->A
    if (b>0){
      if (asize-a < b)
        dfs(asize,b-(asize-a),c);
      else if (asize-a >= b)
        dfs(a+b,0,c);
    }
    // C->A
    if (c>0){
      if (asize-a < c)
        dfs(asize,b,c-(asize-a));
      else if (asize-a >= c)
        dfs(a+c,b,0);
    }
  }
  // B가 받을 수 있는 경우
  if (bsize-b > 0){
    // A->B
    if (a>0){
      if (bsize-b < a)
        dfs(a-(bsize-b),bsize,c);
      else if (bsize-b >= a)
        dfs(0,a+b,c);
    }
    // C->B
    if (c>0){
      if (bsize-b < c)
        dfs(a,bsize,c-(bsize-b));
      else if (bsize-b >= c)
        dfs(a,b+c,0);
    }
  }
  // C가 받을 수 있는 경우
  if (csize-c > 0){
    //A->C
    if(a>0){
      if (csize-c < a)
        dfs(a-(csize-c),b,csize);
      else if (csize-c >= a)
        dfs(0,b,a+c);
    }
    //B->C
    if(b>0){
      if(csize-c < b)
        dfs(a,b-(csize-c),csize);
      else if(csize-c >= b)
        dfs(a,0,b+c);
    }
  }
  
  return;
}

int main()
{
  cin >> asize >> bsize >> csize;
  
  dfs(0,0,csize);
  
  sort(ans.begin(), ans.end());
  for (int i=0; i<ans.size(); i++){
    cout << ans[i] << ' ';
  }
}
