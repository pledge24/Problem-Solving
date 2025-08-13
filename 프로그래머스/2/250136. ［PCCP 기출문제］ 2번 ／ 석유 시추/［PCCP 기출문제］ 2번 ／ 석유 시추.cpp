#include <bits/stdc++.h>

#define NONE 0
#define OIL 1
#define DIR 4

using namespace std;
using Matrix = vector<vector<int>>;
using Pos = pair<int, int>;

int N, M;
int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

bool InRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

void Bfs(Matrix& land, Matrix& matrix, map<int, int>& m1, int setId, Pos start){
    queue<Pos> q;
    q.push(start);
    matrix[start.first][start.second] = setId;
    m1[setId]++;
    
    while(!q.empty()){
        Pos cur = q.front(); q.pop();
        
        for(int i = 0; i < DIR; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(InRange(nx, ny) && land[nx][ny] == OIL && matrix[nx][ny] == NONE/*visited 역할도 함*/){
                q.push(make_pair(nx, ny));
                matrix[nx][ny] = setId;
                m1[setId]++;
            }
            
        } 
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    N = land.size();
    M = land[0].size();
    
    Matrix matrix(N, vector<int>(M));
    map<int, int> m1; // <셋 번호, 크기>
    // vector<vector<bool>> visited(N, vector<bool>(M));
    int setId = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            // 발견되지 않은 석유인 경우.
            if(land[i][j] == OIL && matrix[i][j] == NONE){
                Bfs(land, matrix, m1, setId, make_pair(i, j));
                setId++;
            }
        }
    }
    
    int maxN = 0;
    for(int col = 0; col < M; col++){
        set<int> s1;
        for(int row = 0; row < N; row++){
            if(matrix[row][col] > 0)
                s1.insert(matrix[row][col]);
        }
        
        int totalOil = 0;
        for(int elem : s1){
            totalOil += m1[elem];
        }
        
        maxN = max(maxN, totalOil);
    }
    
    answer = maxN;
    
    return answer;
}