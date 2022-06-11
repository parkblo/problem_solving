#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct candidate{
	int vote,num,time;
}CDD;

bool cmp(CDD v1, CDD v2)
{
	if (v1.vote > v2.vote)
		return true;

	return false;
}

bool anscmp(CDD v1, CDD v2)
{
	if (v1.num < v2.num)
		return true;

	return false;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<CDD> v;

	for (int i=0; i<m; i++){
		int tmp;
		bool flag=false;
		
		cin >> tmp;

		// 벡터에 같은 번호 있는지 찾기 (완전탐색)
		for (int j=0; j<v.size(); j++){
			if (v[j].num == tmp){
				v[j].vote++;
				flag = true;
				break;
			}
		}

		// 같은 번호를 못 찾았을 경우
		if (!flag)
		{
			// 벡터에 자리가 다 안 찬 경우
			if (v.size() < n)
			{
				v.push_back({1,tmp,i});
			}
			else // 3번 조건 수행
			{
				int currMinIdx = v.size()-1;
				for (int j=v.size()-2; j>=0; j--){
					// 가장 적은 학생이 다수일 경우 갱신하기
					if (v[j].vote > v[currMinIdx].vote)
					{
						break; // 여기 수정
					}
					else
					{
						if (v[j].time < v[currMinIdx].time)
						currMinIdx = j;
					}
				}
				// erase하고 새로운 입후보
				v.erase(v.begin() + currMinIdx);
				v.push_back({1,tmp,i});
			}
		}

		// 계속해서 sort하여 내림차순 지켜주기
		sort(v.begin(), v.end(), cmp);
	}

	// 출력양식을 지키기 위한 sort
	sort(v.begin(), v.end(), anscmp);
	
	for (int i=0; i<v.size(); i++)
	{
		cout << v[i].num << ' ';
	}
}
