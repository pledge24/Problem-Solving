#include <bits/stdc++.h>

#define DIR 4

using namespace std;
using Matrix = vector<vector<char>>;
using Pos = pair<int, int>;

int N;
int M;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

bool InRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

// 특정 종류 컨테이너의 출고 요청이 들어오면, 접근 가능한 모든 컨테이너를 뺀다.
// 알파벳이 두 번 반복되면 모든 컨테이너를 꺼낸다.
// -> 모든 요청이 끝났을때, 남은 컨테이너의 수는?

// stoarge: 직사각형 형태의 컨테이너 배치
// request: 요청 수

void RemoveAll(Matrix& matrix, char c){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(matrix[i][j] == c)
                matrix[i][j] = '.';
        }
    }
}

void Bfs(Matrix& matrix, char c){
    vector<vector<bool>> visited(N, vector<bool>(M));
    
    queue<Pos> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    
    vector<Pos> res;
    while(!q.empty()){
        Pos cur = q.front(); q.pop();
        
        for(int i = 0; i < DIR; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(!InRange(nx, ny) || visited[nx][ny] == true)
                continue;
            
            if(matrix[nx][ny] == '.'){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
            else if(matrix[nx][ny] == c){
                res.push_back(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
            
        }
    }
    
    for(Pos& pos : res){
        matrix[pos.first][pos.second] = '.';
    }
    
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    // 패딩끼고 만든다.
    N = storage.size() + 2;
    M = storage[0].size() + 2;
    
    // cout << N << " " << M << '\n';
    
    Matrix matrix(N, vector<char>(M, '.'));
    for(int i = 0; i < storage.size(); i++){
        string& str = storage[i];
        for(int j = 0; j < str.length(); j++){
            matrix[i+1][j+1] = str[j];
        }
    }
    

    
    for(string req : requests)
    {
        char containerType = req[0];
        if(req.length() == 2){
            RemoveAll(matrix, containerType);
        }
        else{
            Bfs(matrix, containerType);
        }
        
        // DEBUG: print Matrix
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < M; j++){
        //         cout << matrix[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }    
    
    // count Left Contianer
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            answer += matrix[i][j] != '.';
        }
    }
    
    return answer;
}