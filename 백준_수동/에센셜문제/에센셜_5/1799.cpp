#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;

struct posData{
    int x;
    int y;
};

vector<vector<int>> matrix;
int dx[DIR] = {1, 1, -1, -1};
int dy[DIR] = {1, -1, 1, -1};
int N;

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

bool isCatched(int x, int y){
    for(int i = 0; i < DIR; i++){

        int nx = x + dx[i];
        int ny = y + dy[i];

        while(inRange(nx, ny)){
            if(matrix[nx][ny] == 3){
                return true;
            }

            nx +=dx[i];
            ny +=dy[i];
        }
    }

    return false;
}

int dfs(int x, int y, int cnt){

    if(cnt == 8){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << matrix[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }
    int maxCnt = cnt;

    for(int i = 0; i < DIR; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        while(inRange(nx, ny)){
            if(matrix[nx][ny] == 1 && !isCatched(nx, ny)){
                matrix[nx][ny] = 3;
                maxCnt = max(maxCnt, dfs(nx, ny, cnt+1));
                matrix[nx][ny] = 1;
            }

            nx+=dx[i];
            ny+=dy[i];
        }
        
    }

    return maxCnt;
}

int main() {
	fastio;
    cin >> N;

    matrix.resize(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> matrix[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(matrix[i][j] == 1){
                matrix[i][j] = 3;

                ans = max(ans, dfs(i, j, 1));
            }      
        }
    }

    cout << ans << '\n';
    
}