#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

#define DIR 4

using namespace std;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};
int maps_r;
int maps_c;

vector<vector<bool>> visited;
vector<string> maps_global;

struct pos_data{
    int x;
    int y;
};

bool inRange(int x, int y){
    return 0 <= x && x < maps_r && 0 <= y && y < maps_c;
}

int bfs(int x, int y){
    int ans = 0;
    queue<pos_data> q;
    q.push({x, y});
    visited[x][y] = true;
    ans += maps_global[x][y] - '0';
    
    while(!q.empty()){
        pos_data cur_pos = q.front(); q.pop();
        
        for(int i = 0; i < DIR; i++){
            int nx = dx[i] + cur_pos.x;
            int ny = dy[i] + cur_pos.y;
            
            if(inRange(nx, ny) && !visited[nx][ny] && maps_global[nx][ny] != 'X'){
                q.push({nx, ny});
                visited[nx][ny] = true;
                ans += maps_global[nx][ny] - '0';
            }
        }
    }
    
    return ans;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    visited.resize(maps.size(), vector<bool>(maps[0].length()));
    swap(maps_global, maps);
    
    maps_r = maps_global.size();
    maps_c = maps_global[0].length();
        
    for(int i = 0; i < maps_r; i++){
        for(int j = 0; j < maps_c; j++){
            if(maps_global[i][j] != 'X' && !visited[i][j]){
                int ans = bfs(i, j);
                if(ans != 0){
                    answer.push_back(ans);
                }
                
            }
        }
    }
    
    // for(int i = 0; i < maps_r; i++){
    //     for(int j = 0; j < maps_c; j++){
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    if(answer.size() == 0){
        answer = {-1};
    }
    else{
        sort(answer.begin(), answer.end());
    }
    
    
    return answer;
}