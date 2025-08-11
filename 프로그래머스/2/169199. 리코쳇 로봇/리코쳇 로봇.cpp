#include <bits/stdc++.h>

#define OUT 
#define DIR 4
#define INF = 100'000'000

using namespace std;
using Matrix = vector<vector<char>>;
using Pos = pair<int, int>;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};
int N, M;

bool InRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

void Bfs(Matrix& matrix, Pos src, Pos dst, int& answer){
    vector<vector<bool>> visited(N, vector<bool>(M));
    queue<pair<Pos, int>> q; // 현재 위치, 이동 거리
    
    // Init.
    answer = -1;
    q.push(make_pair(src, 0));
    visited[src.first][src.second] = true;
    
    while(!q.empty()){
        pair<Pos, int> cur = q.front(); q.pop();
        
        Pos curPos = cur.first;
        int moveN = cur.second;
        
        for(int i = 0; i < DIR; i++ ){
            int nx = curPos.first;
            int ny = curPos.second;
            
            // 벽이나 장애물에 부딫힐때까지 이동
            while(InRange(nx + dx[i], ny + dy[i]) && matrix[nx + dx[i]][ny + dy[i]] != 'D'){
                nx += dx[i];
                ny += dy[i];
            }
            
            // 최종 도착지가 처음 도착한 곳이면 진입.
            if(!visited[nx][ny]){
                Pos nextPos = make_pair(nx, ny);
                
                q.push(make_pair(nextPos, moveN+1));
                visited[nx][ny] = true;
                
                if(nextPos == dst){
                    answer = moveN+1;
                    return;
                }
            }
            
           
        }
        
        
        
    }
}

// 장애물이나 벽에 부딪힐때까지 이동
// 목표 위치에 도달할 수 없다면 -1 리턴
int solution(vector<string> board) {
    int answer = 0;
    
    N = board.size();
    M = board[0].size();
    
    Matrix matrix(N, vector<char>(M));
    Pos src, dst;
    for(int i = 0; i < board.size(); i++){
        string& row = board[i];
        for(int j = 0; j < row.size(); j++){
            char& c = row[j];
            matrix[i][j] = c;
            
            if(c == 'R')
                src = make_pair(i, j);
            else if(c == 'G')
                dst = make_pair(i, j);
        }
    }
    
    Bfs(matrix, src, dst, OUT answer);
    
    return answer;
}