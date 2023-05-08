#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<int, string> m1;
    map<string, int> m2;
    
    for (int i=0; i<players.size(); i++)
    {
        m1[i] = players[i];
        m2[players[i]] = i;
    }
    
    for (int i=0; i<callings.size(); i++)
    {
        int curr = m2[callings[i]];
        string sback = m1[curr-1];
        
        m1[curr-1] = callings[i];
        m1[curr] = sback;
        
        m2[callings[i]] = curr-1;
        m2[sback] = curr;
    }
    
    for (auto a : m1) answer.push_back(a.second);
    
    return answer;
}
