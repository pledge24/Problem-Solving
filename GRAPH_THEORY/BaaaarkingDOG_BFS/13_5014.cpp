#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int F, S, G, U, D; 

bool inRange(int x){
    return 1 <= x && x <= F;
}

int bfs(){
    queue<int> q;
    vector<bool> visited(F+1);

    // 엘레베이터를 사용할 필요가 없는 경우, 0 반환.
    if(S == G) return 0;

    // 엘레베이터를 사용.
    visited[S] = true;
    q.push(S);

    int dx[2] = {U, -D};
    int cnt = 0;
    while(1){
        queue<int> q_temp;
        while(!q.empty()){
            
            int x = q.front();
            q.pop();

            for(int i = 0 ; i < 2; i++){
                int nx = dx[i] + x;
                if(inRange(nx) && !visited[nx]){
                    if(nx == G){
                        //cout << x << '\n';
                        return cnt + 1;
                    }
                    visited[nx] = true;
                    q_temp.push(nx);
                }
            }
            
        }

        cnt++;
        q = q_temp;
        
        if(q.empty()) break;
    }
    return -1;
}

int main() {
	fastio;
    cin >> F >> S >> G >> U >> D;

    int ans = bfs();

    if(ans == -1){
        cout << "use the stairs\n";
    }
    else{
        cout << ans << '\n';
    }
    
}