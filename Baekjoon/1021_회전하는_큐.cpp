#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int ans=0;
deque<int> dq;
vector<int> v;

int command2()
{
    int tmp = dq.front();
    dq.pop_front();
    dq.push_back(tmp);
    ans++;

    return dq.front();
}

int command3()
{
    int tmp = dq.back();
    dq.pop_back();
    dq.push_front(tmp);
    ans++;

    return dq.front();
}

int main()
{
    int n,m;
    cin >> n >> m;

    for (int i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        dq.push_back(tmp);
    }

    for (int i=0; i<m; i++)
        cin >> v[i];

    for (int t=0; t<m; t++)
    {
        if (dq.size() / v[t] >= 2) // 2번 수행이 유리
        {
            int ret = dq.front();
            while (ret != v[t])
            {
                ret = command2();
            }
            dq.pop_front();
        }
        else // 3번 수행이 유리
        {
            int ret = dq.front();
            while (ret != v[t])
            {
                ret = command3();
            }
            dq.pop_front();
        }
    }

    cout << ans << '\n';
    return 0;
}
