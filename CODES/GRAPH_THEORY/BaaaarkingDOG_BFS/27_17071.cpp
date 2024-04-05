#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAXLEN 500000

using namespace std;

int N, K;
vector<vector<int>> v1;

bool inRange(int x){
    return 0 < x && x <= MAXLEN;
}

void bfs(){

    queue<int> q;
    v1[N][0] = 0;
    q.push(N);

    int move_cnt = 0;
    while(!q.empty()){
        int q_size = q.size();
        
        for(int i = 0; i < q_size; i++){
            int cur_pos = q.front(); q.pop();

            vector<int> next_pos = {cur_pos + 1, cur_pos - 1, cur_pos * 2};

            for(int j = 0; j < next_pos.size(); j++){
                if(inRange(next_pos[j]) && v1[next_pos[j]][(move_cnt + 1) % 2] < 0){
                    v1[next_pos[j]][(move_cnt + 1) % 2] = move_cnt + 1;
                    q.push(next_pos[j]);
                }
            }
            
            
        }
       
        move_cnt++;
    }
}

int main() {
	fastio;
    cin >> N >> K;
 
    v1.resize(MAXLEN + 1, vector<int>(2, -1));
    
    bfs();

    int ans = -1;
    int accel_cnt = 0;

    while(K <= MAXLEN){

        if((v1[K][0] <= accel_cnt && (accel_cnt - v1[K][0]) % 2 == 0) || 
        (v1[K][1] <= accel_cnt && (accel_cnt - v1[K][1]) % 2 == 0)){
            ans = accel_cnt;
            break;
        }

        accel_cnt++;
        K += accel_cnt;
    }

    // for(int i = 1; i <= 17; i++){
    //     cout << v1[i][0] << ' ' << v1[i][1] << ' ';
    // }
    // cout << '\n';

    cout << ans << '\n';
}