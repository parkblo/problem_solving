#include <iostream>
using namespace std;

int main()
{
	int X,N,i,a,b,s=0;cin>>X>>N;
	for(i=0;i<N;i++){cin>>a>>b;s+=a*b;}
	if(s==X)cout<<"Yes";else cout<<"No";
}
