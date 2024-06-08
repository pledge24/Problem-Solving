#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAXN 100'000

using namespace std;

struct pos_data_12851
{
    int move_time;
    int visited_cnt = 0;
};

vector<pos_data_12851> v1(MAXN+1);
int N, K; 
int move_cnt = 0;

bool inRange(int x){
    return 0 <= x && x <= MAXN;
}

void bfs(){

    if(N == K){
        v1[K].visited_cnt = 1;
        return;
    }

    queue<int> q;

    v1[N] = {0, 1};
    q.push(N);

    bool found = false;

    while(!q.empty()){
        int q_size = q.size();
        move_cnt++;

        //cout << "q_size "<< q_size << '\n';
        for(int i = 0; i < q_size; i++){
            int x = q.front(); q.pop();
            int dx[3] = {x+1, x-1, x*2};

            for(int dir = 0; dir < 3; dir++){
                int nx = dx[dir];
                
                if(inRange(nx)){
                    if(v1[nx].visited_cnt == 0){
                        v1[nx] = {move_cnt, v1[x].visited_cnt};

                        if(nx == K){
                            found = true;
                        }
                        else{                 
                            q.push(nx);
                        }
                    }
                    else if(v1[nx].move_time == move_cnt){
                        v1[nx].visited_cnt += v1[x].visited_cnt;
                    }
                    
                }
                
            }
        }

        if(found){
            return;
        }

    }
}

int main() {
	fastio;
    cin >> N >> K;
    
    bfs();

    cout << move_cnt << '\n';
    cout << v1[K].visited_cnt << '\n';
}