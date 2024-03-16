#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4
#define MULTIPLE_ICEBERGS 2
#define SINGLE_ICEBERG 1
#define NO_ICEBERG 0

using namespace std;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

vector<vector<int>> matrix;

int N, M; 

bool inRange(int r, int c){
    return 0 <= r && r < N && 0 <= c && c < M;
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

void bfs(int r, int c, vector<vector<int>> &matrix_temp, vector<vector<bool>> &visited){

    queue<pair<int, int>> q;
    q.push(make_pair(r, c));
    visited[r][c] = true;

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();

        int cur_r = p.first;
        int cur_c = p.second;

        int zero_cnt = 0;
        for(int i = 0; i < DIR; i++){
            int nr = cur_r + dx[i];
            int nc = cur_c + dy[i];

            if(inRange(nr, nc)){
                if(matrix[nr][nc]){
                    if(!visited[nr][nc]){
                        q.push(make_pair(nr, nc));
                        visited[nr][nc] = true;
                    }
                }
                else{
                    zero_cnt++;
                }
            }
        }

        matrix_temp[cur_r][cur_c] = max(matrix[cur_r][cur_c] - zero_cnt, 0);
    }

}

int count_and_melting(){
    int cnt = 0;

    vector<vector<int>> matrix_temp(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M));

    bool left_iceberg = false;

    for(int i = 1; i < N-1; i++){
        for(int j = 1; j < M-1; j++){
            if(matrix[i][j] > 0 && !visited[i][j]){
                bfs(i, j, matrix_temp, visited);
                left_iceberg = true;
                cnt++;
            }

            if(cnt > 1) return MULTIPLE_ICEBERGS;
        }
    }

    if(!left_iceberg) return NO_ICEBERG; // !!!!! 중요! (더이상 빙산이 남아있지 않은 경우)

    matrix = matrix_temp;

    //print_matrix();

    return SINGLE_ICEBERG;
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
      
    int cnt = count_and_melting();
    int years = 0;

    while(cnt == SINGLE_ICEBERG){
        years++;
        cnt = count_and_melting();

        //cout << "check\n";

        if(cnt == NO_ICEBERG){
            years = 0;
            break;
        } 
        
    }

    int ans = years;

    cout << ans << '\n';


}