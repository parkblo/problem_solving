#include <iostream>
#include <string>
using namespace std;

int cur=0;
int ar[10001];

int main()
{
    int n;
    cin >> n;

    for (int i=0; i<n; i++)
    {
        string stmp;
        int tmp;

        cin >> stmp;

        if (stmp == "push"){
            cin >> tmp;
            ar[cur] = tmp;
            cur++;
        }
        else if (stmp == "pop"){
            if (cur <= 0) cout << "-1" << '\n';
            else {
                cout << ar[cur-1] << '\n';
                cur--;
            } 
        }
        else if (stmp == "size"){
            cout << cur << '\n';
        }
        else if (stmp == "empty"){
            if (cur) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        else if (stmp == "top"){
            if (cur <= 0) cout << "-1" << '\n';
            else {
                cout << ar[cur-1] << '\n';
            } 
        }
    } 

    return 0;
}
