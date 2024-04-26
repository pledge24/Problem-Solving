#include <string>
#include <vector>
#include <bits/stdc++.h>

#define DIR 4

using namespace std;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, -1, 0, -1};

vector<string> matrix;

struct pos_data{
    int x;
    int y;
};

bool inRange(int x, int y){
    return 0 <= x && x < 5 && 0 <= y && y < 5;
}

bool bfs(int p_x, int p_y){
    
    vector<vector<bool>> visited(5, vector<bool>(5));
    queue<pos_data> q;
    q.push({p_x, p_y});
    visited[p_x][p_y] = true;
    
    int distance = 2;
    // 맨해튼 거리만큼 bfs
    for(int i = 0; i < distance; i++){
        int q_size = q.size();
        
        for(int j = 0; j < q_size; j++){
            
            pos_data cur_pos = q.front(); q.pop();
            
            for(int dir = 0; dir < DIR; dir++){
                int nx = dx[dir] + cur_pos.x;
                int ny = dy[dir] + cur_pos.y;
                
                // 처음 가보는 위치에 파티션이 아닌 뭔가가 있다면 진입.
                if(inRange(nx, ny) && !visited[nx][ny] && matrix[nx][ny] != 'X'){
                    // 그게 사람이면 실패이므로 함수를 나감.
                    if(matrix[nx][ny] == 'P') return false;
                                     
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        
        
    }
    
    return true;
}

bool isOK(vector<string>& waiting_room){
    matrix = waiting_room;
        
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < 5; j++){
            if(matrix[i][j] == 'P'){
                bool isSafe = bfs(i, j);
                //cout << violate << ' ';
                if(!isSafe) return false;
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    matrix.resize(5);
    
    for(vector<string> waiting_room : places){
        bool ans = isOK(waiting_room);
        //cout << ans << '\n';
        
        answer.push_back(ans);
        
    }
    return answer;
}