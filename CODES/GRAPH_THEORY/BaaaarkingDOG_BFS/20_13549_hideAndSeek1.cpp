#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define WAYS 3
#define DUMMY_NUM 100002
#define MAXLEN 200001

using namespace std;

vector<int> move_data;

int N, K;

bool inRange(int n){
    return 0 <= n && n < MAXLEN;
}

int bfs(){
    queue<int> q;
    q.push(N);
    move_data[N] = 0;

    if(N == K) return 0;

    while(!q.empty()){
        int cur_pos = q.front();
        q.pop();

        // printf("cur_pos: %d\n", cur_pos);

        int dx[WAYS] = {cur_pos*2, cur_pos+1, cur_pos-1};
        for(int i = 0; i < WAYS; i++){
            if(inRange(dx[i])){

                int next_cnt = i > 0 ? move_data[cur_pos]+1 : move_data[cur_pos];

                if(next_cnt < move_data[dx[i]]){
                    q.push(dx[i]);
                    move_data[dx[i]] = next_cnt;
                }
                     
            }
        }
    }

    return move_data[K];
}

int main() {
	fastio;
    cin >> N >> K;
    move_data.resize(MAXLEN, DUMMY_NUM);
    
    int ans = bfs();
    
    cout << ans << '\n';
    

}