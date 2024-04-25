#include <string>
#include <vector>
#include <queue>

#define MAXN 100'000'000

using namespace std;

vector<bool> visited;

struct pos_data{
    int x;
    int cnt = 0;
};

bool inRange(int x) {
    return 0 <= x && x <= MAXN;
}

int bfs(int storey){
    queue<pos_data> q;
    
    q.push({storey, 0});
    visited[storey] = true;
    
    vector<int> dx;
    
    for(int i = 1; i <= MAXN; i*=10){
        dx.push_back(i);
        dx.push_back(-i);
    }
    
    while(!q.empty()){
        pos_data cur_pos = q.front(); q.pop();
        
        for(int i = 0; i < dx.size(); i++){
            int nx = cur_pos.x + dx[i];
            
            if(inRange(nx) && !visited[nx]){
                if(nx == 0) return cur_pos.cnt + 1;
                q.push({nx, cur_pos.cnt + 1});
                visited[nx] = true;
            }
        }
    }
}

int solution(int storey) {
    int answer = 0;
    visited.resize(MAXN+1);
    
    answer = bfs(storey);
    
    return answer;
}