#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define HORSE_DIR 8
#define WALL 1
#define DIR 4

using namespace std;

int K, W, H;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

int dx_horse[HORSE_DIR] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy_horse[HORSE_DIR] = {1, 2, 2, 1, -1, -2, -2, -1};

struct pos_data
{
    int r;
    int c;
    int move_cnt;
    int use_horse_move;
};

vector<vector<int>> matrix;
vector<vector<vector<int>>> move_data;

bool inRange(int r, int c){
    return 1 <= r && r <= H && 1 <= c && c <= W;
}

int bfs(){

    if(H == 1 && W == 1) return 0;
    
    queue<pos_data> q;
    move_data[1][1][0] = 1;
    q.push({1, 1, 1, 0});

    while(!q.empty()){
        pos_data p = q.front();
        q.pop();

        int cur_r = p.r;
        int cur_c = p.c;

        // 말의 이동으로 움직임
        if(p.use_horse_move < K){
            for(int i = 0; i < HORSE_DIR; i++){
                int nr = cur_r + dx_horse[i];
                int nc = cur_c + dy_horse[i];

                if(inRange(nr, nc) && matrix[nr][nc] != WALL && !move_data[nr][nc][p.use_horse_move + 1]){
                    //printf("nr: %d, nc: %d p.move_cnt: %d\n", nr, nc, p.move_cnt + 1);

                    if(nr == H && nc == W){
                        return p.move_cnt;
                    }
                    move_data[nr][nc][p.use_horse_move + 1] = p.move_cnt + 1;
                    q.push({nr, nc, p.move_cnt + 1, p.use_horse_move + 1});
                }
            }
        }
        
        // 상하좌우 움직임
        for(int i = 0; i < DIR; i++){
            int nr = cur_r + dx[i];
            int nc = cur_c + dy[i];

            if(inRange(nr, nc) && matrix[nr][nc] != WALL && !move_data[nr][nc][p.use_horse_move]){
                //printf("nr: %d, nc: %d p.move_cnt: %d\n", nr, nc, p.move_cnt + 1);

                if(nr == H && nc == W){
                    return p.move_cnt;
                }
                move_data[nr][nc][p.use_horse_move] = p.move_cnt + 1;
                q.push({nr, nc, p.move_cnt + 1, p.use_horse_move});
            }
        }

    }

    return -1;
}

int main() {
	fastio;

    cin >> K >> W >> H;
    
    matrix.resize(H+1, vector<int>(W+1));
    move_data.resize(H+1, vector<vector<int>>(W+1, vector<int>(K+1)));

    // input data.
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> matrix[i][j];
        }
    }

    int ans = bfs();

    cout << ans << '\n';

}