#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;


void startTest(){
    int s, t; cin >> s >> t;

    // based BFS

    queue<pair<int, string>> q;
    q.push({s, ""});

    const int MAXN = 10000;

    vector<bool> visited(MAXN);
    enum {D, S, L, R};
    while(!q.empty()){
        pair<int, string> cur = q.front(); q.pop();

        const int enumN = 4;
        for(int i = 0; i < enumN; i++){
            int num;
            switch (i)
            {
            case D:
                num = (cur.first << 1) % MAXN;

                // 이미 확인한 숫자인 경우
                if(visited[num])
                    continue;

                if(num == t){
                    cout << cur.second + "D" << '\n';
                    return;
                }

                visited[num] = true;
                q.push({num, cur.second + "D"});

                break;
            case S:
                num = cur.first - 1 >= 0 ? cur.first - 1 : MAXN-1;

                // 이미 확인한 숫자인 경우
                if(visited[num])
                    continue;

                if(num == t){
                    cout << cur.second + "S" << '\n';
                    return;
                }

                visited[num] = true;
                q.push({num, cur.second + "S"});

                break;
            case L:
                num = (cur.first*10 + cur.first / 1000) % MAXN;

                // 이미 확인한 숫자인 경우
                if(visited[num])
                    continue;

                if(num == t){
                    cout << cur.second + "L" << '\n';
                    return;
                }

                visited[num] = true;
                q.push({num, cur.second + "L"});

                break;                         
            case R:
                num = (cur.first / 10 + (cur.first % 10) * 1000) % MAXN;

                // 이미 확인한 숫자인 경우
                if(visited[num])
                    continue;

                if(num == t){
                    cout << cur.second + "R" << '\n';
                    return;
                }

                visited[num] = true;
                q.push({num, cur.second + "R"});

                break;              
            default:
                break;
            }
        }
    }

}

int main(void){
    fastio;
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        startTest();
    }
    return 0;
}