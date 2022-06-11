#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    unordered_map<string,int> hash;
    
    for (int i=0; i<clothes.size(); i++)
        hash[clothes[i][1]]+=1;
    
    int answer = 1;
    for (auto itr=hash.begin(); itr!=hash.end(); ++itr)
        answer *= (itr->second)+1; // 종류 당 안입는 경우를 고려해서 +1
    
    return answer-1; // 아무것도 선택하지 않은 한 경우 제외
}
