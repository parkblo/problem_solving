#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> p,s;
    
    for (int i=0; i<progresses.size(); i++)
        p.push(progresses[i]);
    for (int i=0; i<speeds.size(); i++)
        s.push(speeds[i]);
    
    int d=1;
    while (!p.empty())
    {
        int pt = p.front() + s.front()*d;
        int cnt = 0;
        if (pt >= 100)
        {
            p.pop();
            s.pop();
            cnt++;
            while (!p.empty())
            {
                pt = p.front() + s.front()*d;
                if (pt >= 100)
                {
                    p.pop();
                    s.pop();
                    cnt++;
                }
                else break;
            }
            answer.push_back(cnt);
        }
        d++;
    }
    return answer;
}
