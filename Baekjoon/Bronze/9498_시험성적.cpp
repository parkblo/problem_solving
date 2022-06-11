#include <iostream>
using namespace std;

int main()
{
    int tmp;
    cin >> tmp;
    if (tmp >= 90) cout << "A";
    else if (tmp >= 80) cout << "B";
    else if (tmp >= 70) cout << "C";
    else if (tmp >= 60) cout << "D";
    else cout << "F";

    return 0;
}
