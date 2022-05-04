#include <string>
#include <vector>

using namespace std;

// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
// 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 총26

string solution(string s, int n) {
    string answer = "";
    answer.resize(s.size());
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]<='z' && s[i]+n>'z'){
            answer[i] = 'a' + s[i]+n-'z'-1;
        }
        else if (s[i]<='Z' && s[i]+n>'Z'){
            answer[i] = 'A' + s[i]+n-'Z'-1;
        }
        else if (s[i] == ' '){
            answer[i] = s[i];
        }
        else {
            answer[i] = s[i]+n;
        }
    }
    return answer;
}
