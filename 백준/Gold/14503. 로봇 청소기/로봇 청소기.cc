#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;
using Matrix = vector<vector<int>>;

// 시계방향임. (북 시작)
int dx[DIR] = {-1, 0, 1, 0};
int dy[DIR] = {0, 1, 0, -1};
int N, M; 

struct PosData{
    int r;
    int c;
    int dir;
};

void printMatrix(Matrix& matrix){
    cout << '\n';
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

int bfs(Matrix& matrix, PosData startPos){
    int cnt = 0;
    const int CLEAR = 9;

    queue<PosData> q;
    q.push(startPos);
    matrix[startPos.r][startPos.c] = CLEAR;
    cnt++;

    while(!q.empty()){
        PosData curPos = q.front(); q.pop();

        bool flag = false;
        for(int i = 0; i < DIR; i++){
            int nx = curPos.r + dx[i];
            int ny = curPos.c + dy[i];

            if(inRange(nx, ny) && matrix[nx][ny] == 0/*empty space*/){
                flag = true;
                break;
            }
        }

        if(flag){
            int nextDir = curPos.dir > 0 ? curPos.dir - 1 : DIR-1;
            int nx = curPos.r + dx[nextDir];
            int ny = curPos.c + dy[nextDir];

            if(inRange(nx, ny) && matrix[nx][ny] == 0/*empty space*/){
                q.push({nx, ny, nextDir});
                matrix[nx][ny] = CLEAR;
                cnt++;
            }
            else{
                q.push({curPos.r, curPos.c, nextDir});
            }

            // printMatrix(matrix);

            continue;
        }


        // if don't move,
        int nx = curPos.r - dx[curPos.dir];
        int ny = curPos.c - dy[curPos.dir];

        if(inRange(nx, ny) && matrix[nx][ny] != 1/*Wall*/){
            q.push({nx, ny, curPos.dir});
        }
    }

    return cnt;
}

int main(void){
    fastio;
    cin >> N >> M;
    int startR, startC, dir; cin >> startR >> startC >> dir;
    Matrix matrix(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> matrix[i][j];
        }
    }

    int ans = bfs(matrix, {startR, startC, dir});

    cout << ans << '\n';
    
    return 0;
}

// 7
// 110
// 38+13 51