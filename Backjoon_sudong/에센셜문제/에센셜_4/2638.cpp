#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4
#define EXPOSED 9

using namespace std;
using Pos = pair<int, int>;

int N, M;
int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

void bfs(vector<vector<int>>& matrix, Pos startPos){
    queue<Pos> q;

    q.push(startPos);
    matrix[startPos.first][startPos.second] = EXPOSED;

    while(!q.empty()){
        Pos pos = q.front(); q.pop();

        for(int d = 0; d < DIR; d++){
            int nx = pos.first + dx[d];
            int ny = pos.second + dy[d];

            if(inRange(nx, ny) && matrix[nx][ny] == 0){
                q.push(make_pair(nx, ny));
                matrix[nx][ny] = EXPOSED;
            }
                
        }
    }
}

void simulate(vector<vector<int>>& matrix, queue<Pos>& cheesePos){

    queue<Pos> removedList;
    int size = cheesePos.size();

    for(int i = 0; i < size; i++){
        Pos pos = cheesePos.front(); cheesePos.pop();
        int cnt = 0;
        for(int d = 0; d < DIR; d++){
            int nx = pos.first + dx[d];
            int ny = pos.second + dy[d];

            if(inRange(nx, ny) && matrix[nx][ny] == EXPOSED)
                cnt++;
        }

        if(cnt < 2/*2방향 이상 노출된 경우 아님*/){
            cheesePos.push(pos);
        }
        else{
            removedList.push(pos);
        }
    }

    while(!removedList.empty()){
        Pos pos = removedList.front(); removedList.pop();
        // cout << pos.first << " " << pos.second << '\n';
    
        // calculate exposed space
        bfs(matrix, pos);
    }
}

void printMatrix(vector<vector<int>>& matrix){
    cout << '\n';

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

}

int main(void){
    fastio;
    cin >> N >> M;
    vector<vector<int>> matrix(N, vector<int>(M));
    queue<Pos> cheesePos;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 1){
                cheesePos.push(make_pair(i, j));
            }
        }
    }

    // calculate exposed space
    bfs(matrix, make_pair(0, 0));

    int T = 0;
    while(!cheesePos.empty()){
        simulate(matrix, cheesePos);
        T++;

        // printMatrix(matrix);
    }

    int ans = T;
    cout << ans << '\n';

    return 0;
}