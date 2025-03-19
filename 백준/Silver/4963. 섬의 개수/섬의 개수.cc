#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 8

using namespace std;
using Matrix = vector<vector<int>>;
using Pos = pair<int, int>;

int W, H; 
int dx[DIR] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[DIR] = {0, 1, 1, 1, 0, -1, -1, -1};

bool inRange(int x, int y){
    return 0 <= x && x < H && 0 <= y && y < W;
}

void bfs(Matrix& matrix, Pos start){

    queue<Pos> q;
    q.push(start);
    matrix[start.first][start.second] = 0;

    while(!q.empty()){
        Pos cur = q.front(); q.pop();

        for(int i = 0; i < DIR; i++){
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;

            if(inRange(nx, ny) && matrix[nx][ny] == 1){
                q.push(make_pair(nx, ny));
                matrix[nx][ny] = 0;
            }
        }
    }
}

int main(void){
    fastio;

    while(true){
        cin >> W >> H;

        if(make_pair(W, H) == make_pair(0, 0))
            break;

        {
            // Input Data
            Matrix matrix(H, vector<int>(W));
            for(int i = 0; i < H; i++){
                for(int j = 0; j < W; j++){
                    cin >> matrix[i][j];
                }
            }

            int cnt = 0;
            for(int i = 0; i < H; i++){
                for(int j = 0; j < W; j++){
                    if(matrix[i][j] == 1){
                        bfs(matrix, make_pair(i, j));
                        cnt++;
                    }
                }
            }

            cout << cnt << '\n';

        }

    }



    return 0;
}