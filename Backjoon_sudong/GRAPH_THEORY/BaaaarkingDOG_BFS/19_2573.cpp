#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

vector<vector<int>> matrix;

int N, M; 

bool inRange(int r, int c){
    return 0 <= r && r < N && 0 <= c && c < M;
}

void bfs(int i, int j, vector<vector<bool>> &visited){
    
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    visited[i][j] = true;

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();

        int cur_r = p.first;
        int cur_c = p.second;

        for(int i = 0; i < DIR; i++){
            int nr = cur_r + dx[i];
            int nc = cur_c + dy[i];

            if(inRange(nr, nc) && matrix[nr][nc] && !visited[nr][nc]){
                visited[nr][nc] = true;
                q.push(make_pair(nr, nc));
            }
        }

        
    }

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < M; j++){
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
}

int get_icebergs_cnt(){
    vector<vector<bool>> visited(N, vector<bool>(M));
    int cnt = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(matrix[i][j] && !visited[i][j]){
                bfs(i, j, visited);
                cnt++;
            }

            if(cnt > 1) return 2;
        }
    }

    return cnt;
}

int get_melted_ice(int r, int c){
    int melted_cnt = 0;

    for(int i = 0; i < DIR; i++){
        int nr = r + dx[i];
        int nc = c + dy[i];

        if(inRange(nr, nc) && !matrix[nr][nc]){
            melted_cnt++;
        }
    }

    int melted_iceberg = matrix[r][c] - melted_cnt >= 0 ? matrix[r][c] - melted_cnt: 0;
    return melted_iceberg;
}

void time_flow(){
    vector<vector<int>> matrix_temp(N, vector<int>(M));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(matrix[i][j]){
                matrix_temp[i][j] = get_melted_ice(i, j);
            }
        }
    }

    matrix = matrix_temp;
}

void print_matrix(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
	fastio;
    cin >> N >> M;

    matrix.resize(N, vector<int>(M));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> matrix[i][j]; 
        }
    }
      
    int cnt = get_icebergs_cnt();
    int years = 0;

    while(cnt < 2){

        time_flow();
        years++;

        cnt = get_icebergs_cnt();
    }

    int ans = years;

    cout << ans << '\n';


}