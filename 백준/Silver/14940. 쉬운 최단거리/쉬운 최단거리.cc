#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;

int n, m;
int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

vector<vector<int>> matrix;
vector<vector<bool>> visited;

bool inRange(int r, int c){
    return 0 <= r && r < n && 0 <= c && c < m;
}

void bfs(pair<int, int> start_pos){

    queue<pair<int, int>> q;

    // 방문처리
    q.push(start_pos);
    visited[start_pos.first][start_pos.second] = true;

    while(!q.empty()){
        pair<int, int> p = q.front(); q.pop();
        int r = p.first;
        int c = p.second;

        for(int i = 0; i < DIR; i++){
            int nx = r + dx[i];
            int ny = c + dy[i];

            if(inRange(nx, ny) && matrix[nx][ny] == 1 && !visited[nx][ny]){
                // 방문처리
                q.push({nx, ny});
                visited[nx][ny] = true;

                matrix[nx][ny] = matrix[r][c] + 1;
            }

        }
    }
}

int main(void){
    fastio;

    cin >> n >> m;

    visited.resize(n, vector<bool>(m));
    matrix.resize(n, vector<int>(m));

    pair<int, int> start_pos;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];

            if(matrix[i][j] == 2){
                start_pos = {i, j};
                matrix[i][j] = 0;
            }
            
        }
    }

    bfs(start_pos);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] != 0 && !visited[i][j]){
                matrix[i][j] = -1;
            }
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}