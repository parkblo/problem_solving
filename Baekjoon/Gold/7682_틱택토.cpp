#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int dr[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

typedef struct position{
    int a,b,cnt,dir;
}Pos;

bool Condition(int a, int b, char c, char ar[3][3])
{
    if (a<0 || b<0 || a>=3 || b>=3)
        return false;
    if (ar[a][b] != c)
        return false;
    
    return true;
}

int BFS(char ar[3][3], char c)
{
    int ret=0;
    queue<Pos> q;

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (ar[i][j] != c) continue;

            q.push({i,j,1,-1});
            while (!q.empty())
            {
                int curA = q.front().a;
                int curB = q.front().b;
                int curC = q.front().cnt;
                int curD = q.front().dir;
                q.pop();

                if (curC == 3) { ret++; continue; }

                int nextA,nextB;
                if (curD != -1){
                    nextA = curA + dr[curD][0];
                    nextB = curB + dr[curD][1];

                    if (Condition(nextA,nextB,c,ar)){
                        q.push({nextA,nextB,curC+1,curD});
                    }
                }
                else {
                    for (int k=0; k<8; k++){
                        nextA = curA + dr[k][0];
                        nextB = curB + dr[k][1];

                        if (Condition(nextA,nextB,c,ar)){
                            q.push({nextA,nextB,curC+1,k});
                        }
                    }
                }

            }
        }
    }

    return ret;
}

int main()
{
    while (1)
    {
        int Ost=0, Xst=0, Ocnt=0, Xcnt=0;
        bool flag = true;
        string stmp;

        cin >> stmp;

        if (stmp == "end") break;

        char ar[3][3];
        for (int i=0, cnt=0; i<3; i++){
            for (int j=0; j<3; j++, cnt++){
                if (stmp[cnt] == 'O') Ocnt++;
                else if (stmp[cnt] == 'X') Xcnt++;

                ar[i][j] = stmp[cnt];
            }
        }

        Ost = BFS(ar,'O');
        Xst = BFS(ar,'X');

        if (Xcnt < Ocnt || Xcnt > Ocnt+1) flag = false;
        if (Xst>0 && Ost>0) flag = false;
        else if (Xst==0 && Ost==0){
            if (Xcnt != 5 || Ocnt != 4) flag = false;
        }
        else if (Xst>0) {
            if (Xcnt <= Ocnt) flag = false;
        }
        else if (Ost>0) {
            if (Xcnt != Ocnt) flag = false;
        }

        if (flag) cout << "valid" << '\n';
        else cout << "invalid" << '\n';
    }

    return 0;
}
