#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4
#define NO_USE_PASS 0
#define USE_PASS 1

using namespace std;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

int N, M; 

struct move_data
{
    int r;
    int c;
    int move_cnt;
    bool use_wall_pass;
};

vector<vector<int>> matrix;
vector<vector<array<int, 2>>> visited_data;   // [0]: 벽 통과 사용 X 최소 이동 횟수, [1]: 벽 통과 사용 O 최소 이동 횟수

bool inRange(int r, int c){
    return 1 <= r && r <= N && 1 <= c && c <= M;
}

bool isPromise(move_data md){
    int cur_r = md.r;
    int cur_c = md.c;

    if(md.use_wall_pass){           // 벽 통과를 사용한 경우.
        bool isWall = matrix[cur_r][cur_c] == 1;
        // 기본 조건
        // 1. 벽이 아니어야 한다(벽 통과는 한 번만 가능).
        // 2. 벽 통과를 사용하여 해당 칸을 방문한 적이 없어야 한다.
        if( !isWall && !visited_data[cur_r][cur_c][USE_PASS]){
            // 유망한 조건: 벽 통과를 사용하지 않고 이동했을 경우가 존재할 시, 해당 횟수보다 작아야한다.
            if(visited_data[cur_r][cur_c][NO_USE_PASS] && visited_data[cur_r][cur_c][NO_USE_PASS] > md.move_cnt){
                return true;
            }
            else if (!visited_data[cur_r][cur_c][NO_USE_PASS])
            {
                return true;
            }
                     
        }
        
    }
    else{                           // 벽 통과를 사용하지 않은 경우.
        // 벽 통과를 사용하지 않고 해당 칸을 방문한 적이 없어야 한다.
        if(!visited_data[cur_r][cur_c][NO_USE_PASS]){
            return true;
        }
    }

    return false;
}

int bfs(){
    queue<move_data> q;
    
    q.push({1, 1, 1, false});
    visited_data[1][1][NO_USE_PASS] = 1;

    if(N*M == 1) return 1;
    
    while(!q.empty()){
        move_data curr_pos = q.front();
        q.pop();

        for(int i = 0; i < DIR; i++){
            int nr = curr_pos.r + dx[i];
            int nc = curr_pos.c + dy[i];

            if(inRange(nr, nc) && isPromise({nr, nc, curr_pos.move_cnt+1, curr_pos.use_wall_pass})){
                bool isWall = matrix[nr][nc] == 1;

                // if(nr == 1 && nc == 1){
                //     printf("cur_r, cur_c = (%d, %d)\n", curr_pos.r, curr_pos.c);
                // }
                // 도착점에 도착한 경우, 해당 이동 횟수 반환(정답).
                if(nr == N && nc == M){
                    return curr_pos.move_cnt+1;
                }

                // 이동하는 곳이 벽이거나, 벽을 통과한 이력이 있는 경우.
                if(curr_pos.use_wall_pass || isWall){
                    q.push({nr, nc, curr_pos.move_cnt+1, true});
                    visited_data[nr][nc][USE_PASS] = curr_pos.move_cnt+1;
                }
                else{
                    q.push({nr, nc, curr_pos.move_cnt+1, false});
                    visited_data[nr][nc][NO_USE_PASS] = curr_pos.move_cnt+1;
                }
             
            }
        }


    }
   
    return -1;
}

int main() {
	fastio;
    cin >> N >> M;
    matrix.resize(N+1, vector<int>(M+1));
    visited_data.resize(N+1, vector<array<int, 2>>(M+1));

    // input data.
    string str;
    for(int i = 1; i <= N; i++){
        cin >> str;
        for(int j = 1; j <= M; j++){
            matrix[i][j] = str[j-1] - '0';
        }   
    }

    int ans = bfs();

    //cout << "ans" << '\n';
    cout << ans << '\n';
}