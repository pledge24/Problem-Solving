#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

using namespace std;

struct pos_data
{
    int x;
    int y;
};

int N; 

queue<pos_data> q;
vector<vector<int>> matrix;

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

void bfs(){

    while(!q.empty()){
        pos_data cur_pos = q.front(); q.pop();

        for(int i = 0; i < DIR; i++){
            int nx = cur_pos.x + dx[i];
            int ny = cur_pos.y + dy[i];

            if(inRange(nx, ny) && (matrix[nx][ny] == 0)){
                //cout << nx << " " << ny << '\n';
                //cout << matrix[nx][ny] << '\n';
                matrix[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
	fastio;
    cin >> N;
   
    matrix.resize(N, vector<int>(N));

    int num;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> num;
            if(num == 2){
                //cout << i << " " << j << '\n';
                q.push({i, j});
            }
            matrix[i][j] = num;
        }
    }
    
    bfs();

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            //cout << matrix[i][j] << " ";
            if(matrix[i][j] == 0) ans++;
        }
        cout << '\n';
    }

    cout << ans << '\n';
}