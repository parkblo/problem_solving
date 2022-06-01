#include <iostream>
#include <vector>
          #include <map>
          #include <algorithm>
        
        
          
          using namespace std;
        
        
          
          

        
        
          
          const int MAX = 8;
        
        
          
          

        
        
          
          int N, M;
        
        
          
          vector<int> v;
        
        
          
          int visited[MAX];
        
        
          
          map<int, int> numberCnt;
        
        
          
          

        
        
          
          void func(int idx, int start, int cnt)
        
        
          
          {
        
        
          
          	if (cnt == M)
        
        
          
          	{
        
        
          
          		for (int i = 0; i < M; i++)
        
        
          
          		{
        
        
          
          			cout << v[visited[i]] << " ";
        
        
          
          		}
        
        
          
          		cout << "\n";
        
        
          
          

        
        
          
          		return;
        
        
          
          	}
        
        
          
          

        
        
          
          	if (idx == N)
        
        
          
          	{
        
        
          
          		return;
        
        
          
          	}
        
        
          
          

        
        
          
          	for (int i = start; i < v.size(); i++)
        
        
          
          	{
        
        
          
          		if (numberCnt[v[i]])
        
        
          
          		{
        
        
          
          			numberCnt[v[i]]--;
        
        
          
          

        
        
          
          			visited[idx] = i;
        
        
          
          			func(idx + 1, i, cnt + 1);
        
        
          
          

        
        
          
          			numberCnt[v[i]]++;
        
        
          
          		}
        
        
          
          	}
        
        
          
          }
        
        
          
          

        
        
          
          int main(void)
        
        
          
          {
        
        
          
          	ios_base::sync_with_stdio(0);
        
        
          
          	cin.tie(0);
        
        
          
          	cin >> N >> M;
        
        
          
          

        
        
          
          	for (int i = 0; i < N; i++)
        
        
          
          	{
        
        
          
          		int num;
        
        
          
          		cin >> num;
        
        
          
          

        
        
          
          		if (!numberCnt.count(num))
        
        
          
          		{
        
        
          
          			numberCnt[num] = 1;
        
        
          
          

        
        
          
          			v.push_back(num);
        
        
          
          		}
        
        
          
          		else
        
        
          
          		{
        
        
          
          			numberCnt[num]++;
        
        
          
          		}
        
        
          
          	}
        
        
          
          

        
        
          
          	sort(v.begin(), v.end());
        
        
          
          

        
        
          
          	func(0, 0, 0);
        
        
          
          

        
        
          
          	return 0;
        
        
          
          }
