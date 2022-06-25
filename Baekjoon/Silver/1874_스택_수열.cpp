#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    queue<int> num, ins;
    queue<char> ans;
    stack<int> S;

    cin >> n;

    for (int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        ins.push(tmp);
    }

    for (int i=1; i<=n; i++){
        num.push(i);
    }

    while (!num.empty())
    {
		if (S.empty()){
			ans.push('+');
			S.push(num.front());
			num.pop();
			continue;
		}
		
        if (S.top() == ins.front()){
            ans.push('-');
            S.pop();
            ins.pop();
        }
        else {
            ans.push('+');
            S.push(num.front());
            num.pop();
        }
    }

	while (!S.empty()){
		if (S.top() == ins.front()){
            ans.push('-');
            S.pop();
            ins.pop();
        }
        else {
            ans.push('-');
            S.pop();
        }
	}

    if (ins.empty()){
        while (!ans.empty()){
            cout << ans.front() << '\n';
            ans.pop();
        }
    }
    else {
        cout << "NO\n";
    }

    return 0;
}
