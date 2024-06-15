#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;

int N, M, K;
vector<vector<int>> matrix;
vector<vector<vector<bool>>> visited_data;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

struct pos_data_16933
{
    int x;
    int y;
    int useWallPass = 0;
};

bool inRange(int r, int c){
    return 1 <= r && r <= N && 1 <= c && c <= M;
}

int bfs(){

    // 칸이 하나인 경우 이동 횟수 1 반환.
    if(N == 1 && M == 1) return 1;

    enum maze {room=0, wall};

    queue<pos_data_16933> q;
    q.push({1, 1});

    int move_cnt = 1;
    while(!q.empty()){
        int q_size = q.size();
        bool isNight = !(move_cnt % 2);
        for(int i = 0; i < q_size; i++){
            pos_data_16933 cur_pos_data = q.front(); q.pop();

            int ncnt = cur_pos_data.useWallPass;

            for(int dir = 0; dir < DIR; dir++){
                int nx = cur_pos_data.x + dx[dir];
                int ny = cur_pos_data.y + dy[dir];
                if(inRange(nx, ny)){
                    
                    // (M, N)에 도착.
                    if((nx == N) && (ny == M)){
                        return move_cnt + 1;
                    }

                    if(matrix[nx][ny] == room && !visited_data[nx][ny][ncnt]){ 
                        visited_data[nx][ny][ncnt] = true;                      
                        q.push({nx, ny, ncnt});
                    }
                    else if(matrix[nx][ny] == wall && !isNight && ncnt+1 <= K && !visited_data[nx][ny][ncnt+1]){
                        visited_data[nx][ny][ncnt+1] = true;
                        q.push({nx, ny, ncnt+1});
                    }
                    
                }
            }

            if(isNight){
                visited_data[cur_pos_data.x][cur_pos_data.y][ncnt] = true;
                q.push({cur_pos_data.x, cur_pos_data.y, ncnt});
            }
        }

        //cout << "check2\n";
        move_cnt++;
        
    }


    return -1;
}

int main() {
	fastio;
    cin >> N >> M >> K;
    
    matrix.resize(N+1, vector<int>(M+1));
    visited_data.resize(N+1, vector<vector<bool>>(M+1, vector<bool>(K+1)));
    // input data.
    char c;
    for(int i = 1; i <= N; i++){   
        for(int j = 1; j <= M; j++){
            cin >> c;
            matrix[i][j] = c - '0';
        }
    }
    
    // // print matrix.
    // for(int i = 1; i <= N; i++){   
    //     for(int j = 1; j <= M; j++){
    //         cout << matrix[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int ans = bfs();

    cout << ans << '\n';
}