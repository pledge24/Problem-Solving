#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;
using Grid = vector<vector<int>>;
using Pos = pair<int, int>;

int N, M; 
int dx[DIR] = {-1, 0, 1, 0};
int dy[DIR] = {0, 1, 0, -1};

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

int bfs(Grid &matrix, /*Virus*/queue<Pos> q, Pos p1, Pos p2, Pos p3, int leftSpace){
    vector<vector<bool>> visited(N, vector<bool>(M));

    visited[p1.first][p1.second] = true;
    visited[p2.first][p2.second] = true;
    visited[p3.first][p3.second] = true;

    while(!q.empty()){
        Pos curPos = q.front(); q.pop();

        for(int i = 0; i < DIR; i++){
            int nx = curPos.first + dx[i];
            int ny = curPos.second + dy[i];

            if(inRange(nx, ny) && !visited[nx][ny] && matrix[nx][ny] == 0){
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
                leftSpace--;
            }

        }
    }

    return leftSpace;
}

int main(void){
    fastio;
    cin >> N >> M;

    int leftSpace = N*M;
    queue<Pos> q;

    // input data.
    Grid matrix(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> matrix[i][j];

            if(matrix[i][j] != 0)
                leftSpace--;
                
            if(matrix[i][j] == 2)
                q.push(make_pair(i, j));

        }
    }

    leftSpace -= 3;

    int ans = 0;
    for(int i = 0; i < N*M; i++){
        Pos pos1 = make_pair(i / M, i % M);
        if(matrix[pos1.first][pos1.second] != 0)
            continue;

        for(int j = i+1; j < N*M; j++){
            Pos pos2 = make_pair(j / M, j % M);
            if(matrix[pos2.first][pos2.second] != 0)
                continue;

            for(int k = j+1; k < N*M; k++){
                Pos pos3 = make_pair(k / M, k % M);
                if(matrix[pos3.first][pos3.second] != 0)
                    continue;

                ans = max(ans, bfs(matrix, q, pos1, pos2, pos3, leftSpace));
                // cout << "check" << '\n';
            }
        }
    }

    cout << ans << '\n';

    return 0;
}