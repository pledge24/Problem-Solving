#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;

int N;

vector<vector<int>> matrix;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

bool inRange(int r, int c){
    return 0 <= r && r < N && 0 <= c && c < N;
}

void print_test(vector<vector<bool>> visited){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void bfs(int r, int c, int rain_height, vector<vector<bool>> &visited){
    queue<pair<int, int>> q;

    visited[r][c] = true;
    q.push(make_pair(r, c));

    while(!q.empty()){

        pair<int, int> pos = q.front();
        q.pop();

        int pos_r = pos.first;
        int pos_c = pos.second;

        for(int i = 0; i < DIR; i++){
            int nx = pos_r + dx[i];
            int ny = pos_c + dy[i];

            if(inRange(nx, ny) && !visited[nx][ny] && matrix[nx][ny] > rain_height){
                //printf("nx: %d, ny: %d\n", nx, ny);
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
    
}

int main() {
	fastio;
    cin >> N;
    
    matrix.resize(N, vector<int>(N));

    // input data.
    int max_height = -1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> matrix[i][j];
            max_height = max(max_height, matrix[i][j]);
        }
    }
    
    int rain_height = 1;
    int max_cnt_areas = -1;
    while(rain_height < max_height){
        int cnt = 0;
        
        vector<vector<bool>> visited(N, vector<bool>(N));

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!visited[i][j] && matrix[i][j] > rain_height){
                    bfs(i, j, rain_height, visited);
                    cnt++;
                }
            }
        }

        //cout << cnt << '\n';
        max_cnt_areas = max(max_cnt_areas, cnt);
        //print_test(visited);


        rain_height++;

    }
    
    int ans = max(max_cnt_areas, 1);

    cout << ans << '\n';

    
}