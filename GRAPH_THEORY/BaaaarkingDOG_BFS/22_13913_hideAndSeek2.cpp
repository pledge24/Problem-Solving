#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define WAYS 3
#define DUMMY_NUM 100002
#define MAXLEN 200001

using namespace std;

vector<pair<int,int>> move_data;    // first: cnt, second: prev_num

int N, K;

bool inRange(int n){
    return 0 <= n && n < MAXLEN;
}

bool visited(int pos){
    return move_data[pos].first != DUMMY_NUM;
}

void print_path(){
    vector<int> ans_v1;

    int cur_pos = K;
    while(cur_pos != -1){
        ans_v1.push_back(cur_pos);
        cur_pos = move_data[cur_pos].second;
    }

    for(int i = ans_v1.size()-1; i >= 0; i--){
        cout << ans_v1[i] << ' ';
    }
    cout << '\n';

}

int bfs(){
    queue<int> q;

    q.push(N);
    move_data[N] = make_pair(0, -1);

    if(N == K) return 0;

    while(!q.empty()){
        int cur_pos = q.front();
        q.pop();

        int dx[WAYS] = {cur_pos*2, cur_pos+1, cur_pos-1};
        for(int i = 0; i < WAYS; i++){
            
            if(inRange(dx[i]) && !visited(dx[i])){

                int next_cnt = move_data[cur_pos].first + 1;
                if(dx[i] == K){
                    move_data[dx[i]] = make_pair(next_cnt, cur_pos);
                    return next_cnt;
                }
                     
                q.push(dx[i]);
                move_data[dx[i]] = make_pair(next_cnt, cur_pos);
            }
        }
    }

    return 0;
}

int main() {
	fastio;
    cin >> N >> K;

    move_data.resize(MAXLEN, {DUMMY_NUM, 0});
    
    int ans = bfs();
    
    cout << ans << '\n';

    // for(int i = 0; i <= K+1; i++){
    //     printf("i: %d, cnt: %d, prev_num: %d\n", i, move_data[i].first, move_data[i].second);
    // }
    print_path();

}