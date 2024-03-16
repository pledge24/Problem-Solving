#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4
#define MAX_MOVE 1000001
#define NO_USE_WALL_PASS 0
#define WALL 1

using namespace std;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

int N, M, K; 

struct move_data
{
    int r;
    int c;
    int move_cnt;
    int wall_pass_cnt;
};

vector<vector<int>> matrix;
vector<vector<vector<int>>> visited_data;   // [0]: 벽 통과 사용 X 최소 이동 횟수, [1~K]: 벽 통과 사용 O 최소 이동 횟수

bool inRange(int r, int c){
    return 1 <= r && r <= N && 1 <= c && c <= M;
}

bool isPromise(move_data md){
    int cur_r = md.r;
    int cur_c = md.c;
    int cur_wall_pass_cnt = md.wall_pass_cnt;

    if(cur_wall_pass_cnt <= K){
        
        // 더 적은 횟수의 벽 통과로 해당 위치에 도달하는 최소 이동 횟수를 가져온다.
        int less_use_less_move = 1000001;
        for(int i = 0; i <= cur_wall_pass_cnt; i++){
            int temp_cnt = visited_data[cur_r][cur_c][i];
            less_use_less_move = temp_cnt ? min(less_use_less_move, temp_cnt) : less_use_less_move;
        }

        // 1. 현재 이용한 벽 통과 횟수로 해당 칸을 방문한 적이 없어야 한다.
        // 2. 더 적은 벽 통과로 이동한 횟수보다 이동 횟수가 적어야 한다.
        if(less_use_less_move > md.move_cnt){
            return true;
        }
    }
    
    return false;
}

int bfs(){
    queue<move_data> q;
    
    int start_r = 1;
    int start_c = 1;
    int start_move_cnt = 1;

    q.push({start_r, start_c, start_move_cnt, NO_USE_WALL_PASS});
    visited_data[start_r][start_c][NO_USE_WALL_PASS] = 1;

    if(N*M == 1) return 1;
    
    while(!q.empty()){
        move_data curr_pos = q.front();
        q.pop();

        for(int i = 0; i < DIR; i++){
            int nr = curr_pos.r + dx[i];
            int nc = curr_pos.c + dy[i];

            if(inRange(nr, nc)){
                
                move_data next_move_data = {nr, nc, curr_pos.move_cnt+1, curr_pos.wall_pass_cnt + matrix[nr][nc]};

                bool isMornig = curr_pos.move_cnt % 2;    // 이동 횟수가 홀수이면 낮인 상태.

                // 벽으로 이동하는 경우지만, 밤이라 이동하지 못한다면 이동 횟수를 추가로 1 증가한다
                if(!isMornig && matrix[nr][nc] == WALL){
                    next_move_data.move_cnt++;
                }

                //printf("nr, nc = (%d, %d)\n", nr, nc);
                if(isPromise(next_move_data)){
                    
                    //printf("Promise!\n");
                    
                    visited_data[nr][nc][next_move_data.wall_pass_cnt] = next_move_data.move_cnt;
                    if(nr != N || nc != M){
                        q.push(next_move_data);
                    }
                }
               
         
            }
        }
        
    }
   
    int min_move = *min_element(visited_data[N][M].begin(), visited_data[N][M].end());

    if(min_move != MAX_MOVE){
        return min_move;
    }

    return -1;
}

int main() {
	fastio;
    cin >> N >> M >> K;
    matrix.resize(N+1, vector<int>(M+1));
    visited_data.resize(N+1, vector<vector<int>>(M+1, vector<int>(K+1, MAX_MOVE)));

    // input data.
    string str;
    for(int i = 1; i <= N; i++){
        cin >> str;
        for(int j = 1; j <= M; j++){
            matrix[i][j] = str[j-1] - '0';
        }   
    }

    int ans = bfs();

    cout << ans << '\n';
}