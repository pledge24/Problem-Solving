#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;

vector<vector<int>> matrix;
vector<vector<bool>> visited_data;

int N, M;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

bool inRange(int r, int c){
    return 0 <= r && r < N && 0 <= c && c < M;
}

int bfs(int r, int c){
    queue<pair<int, int>> q;
    
    int areas = 0;

    visited_data[r][c] = true;
    q.push(make_pair(r, c));
    areas++;
    
    while(!q.empty()){

        pair<int, int> pos = q.front();
        q.pop();

        int pos_r = pos.first;
        int pos_c = pos.second;

        for(int i = 0; i < DIR; i++){
            int nx = pos_r + dx[i];
            int ny = pos_c + dy[i];

            if(inRange(nx, ny) && !visited_data[nx][ny] && matrix[nx][ny]){
                //printf("nx: %d, ny: %d\n", nx, ny);

                visited_data[nx][ny] = true;
                q.push(make_pair(nx, ny));
                areas++;
            }
        }
    }

    return areas;
}

int main() {
	fastio;
    cin >> N >> M;

    matrix.resize(N, vector<int>(M));
    visited_data.resize(N, vector<bool>(M));

    // input data.
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> matrix[i][j];
        }
    }

    int ans_cnt = 0;
    int ans_area = 0;   
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            
            // 그림이 있다면 BFS.
            if(matrix[i][j] != 0 && !visited_data[i][j]){
                ans_cnt++;

                int area = bfs(i, j);
                //cout << area << '\n';
                ans_area = max(ans_area, area);
            }
        }
    }

    cout << ans_cnt << '\n';
    cout << ans_area << '\n';
}