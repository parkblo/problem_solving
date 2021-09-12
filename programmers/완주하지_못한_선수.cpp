// https://programmers.co.kr/learn/courses/30/lessons/42576

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    bool complete[200001]={false,};
    
    for (int i=0; i<completion.size(); i++)
    {
        participant.push_back(completion[i]);
    }
    
    sort(participant.begin(),participant.end());
    
    for (int i=1; i<participant.size(); i++)
    {
        if (complete[i] == true || complete[i-1] == true) continue;
        
        if (participant[i] == participant[i-1])
        {
            complete[i] = true;
            complete[i-1] = true;
        }
    }
    
    for (int i=0; i<participant.size(); i++)
    {
        if (complete[i] == false)
        {
            answer += participant[i];
            break;
        }
    }
    
    return answer;
}
