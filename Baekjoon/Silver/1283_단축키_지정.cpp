#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isExist(char c, vector<char> cut)
{
    for (int i=0; i<cut.size(); i++)
    {
        if (c == cut[i]) return true;

        if ((c-'A'+'a') == cut[i]) return true;
        if ((cut[i]-'A'+'a') == c) return true;
    }

    return false;
}

int main()
{
    int n;
    vector<string> v;
    vector<char> cut;

    cin >> n;
    cin.ignore();

    for (int i=0; i<n; i++)
    {
        string stmp;
        getline(cin, stmp);
        v.push_back(stmp);
    }

    for (int i=0; i<v.size(); i++)
    {
        bool flag = false;
        // 1. 단어의 첫 글자가 단축키가 될 때
        for (int j=0; j<v[i].size(); j++)
        {
            if (isExist(v[i][j],cut)) continue;
            if (v[i][j] == ' ') continue;

            if (j == 0) {
                cut.push_back(v[i][j]);
                v[i].insert(0,"[");
                v[i].insert(2,"]");
                flag = true;
                break;
            }
            else if (v[i][j-1] == ' ') {
                cut.push_back(v[i][j]);
                v[i].insert(j+1,"]");
                v[i].insert(j,"[");
                flag = true;
                break;
            }
        }

        if (flag) continue;

        // 2. 왼쪽에서부터 알파벳을 보면서 단축키로 지정
        for (int j=0; j<v[i].size(); j++)
        {
            if (isExist(v[i][j],cut)) continue;
            if (v[i][j] == ' ') continue;

            cut.push_back(v[i][j]);
            v[i].insert(j+1,"]");
            v[i].insert(j,"[");
            flag = true;
            break;
        }
    }

    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << '\n';
    }

    return 0;
}
