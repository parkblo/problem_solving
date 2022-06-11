#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool findStr(string dest, string src)
{
    if (src.size() > dest.size()) return false;
    
    for (int i=0; i<src.size(); i++)
        if (dest[i] != src[i]) return false;
    
    return true; // 일치한다면 TRUE
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(),phone_book.end());
    
    for (int i=0; i<phone_book.size()-1; i++)
    {
        if (findStr(phone_book[i+1],phone_book[i]))
        {
            answer = false;
            break;
        }
    }
    
    return answer;
}
