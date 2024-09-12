#include <string>
#include <vector>
#include <queue>

#define MAXN 1'000'000

using namespace std;

int X, Y, N;

bool inRange(int x){
    return 0 < x && x <= MAXN;
}

int bfs(){
    int ans = 0;
    
    if(X == Y) return 0;
    
    vector<bool> visited(MAXN+1);
    queue<int> q;
    
    visited[X] = true;
    q.push(X);
    
    while(!q.empty()){
        int q_size = q.size();
        ans++;
        
        for(int i = 0; i < q_size; i++){
            int cur_pos = q.front(); q.pop();
            vector<int> next = {cur_pos + N, cur_pos*2, cur_pos*3};

            for(int elem : next){
                if(elem == Y) return ans;

                if(inRange(elem) && !visited[elem]){
                    visited[elem] = true;
                    q.push(elem);
                }
            }
            
        }
        
        
        
        
    }
    
    
    return -1;
}
int solution(int x, int y, int n) {
    X = x;
    Y = y;
    N = n;
    int answer = bfs();
    return answer;
}