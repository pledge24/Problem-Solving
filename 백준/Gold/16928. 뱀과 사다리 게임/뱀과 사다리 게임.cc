#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int MAXN = 100;


int bfs(vector<int> &jumpData, int start){
    
    struct posData{
        int pos;
        int cnt;
    };

    queue<posData> q; 
    vector<bool> visited(MAXN+1);

    q.push({start, 0});
    visited[start] = true;

    int ret = 0;
    const int MAXMOVEMENT = 6;
    while(!q.empty()){
        posData _posData = q.front(); q.pop();
        int pos = _posData.pos;
        int cnt = _posData.cnt;

        for(int i = 1; i <= MAXMOVEMENT; i++){
            int nextPos = pos + i;
            int nextCnt = cnt + 1;
            // peek nextPos
            if(!visited[nextPos] && nextPos <= 100){

                // 뱀 또는 사다리가 있는 경우
                if(jumpData[nextPos] != 0){
                    nextPos = jumpData[nextPos];
                }

                // find Goal
                if(nextPos == 100){
                    return nextCnt;
                }

                if(!visited[nextPos]){
                    q.push({nextPos, nextCnt});
                    visited[nextPos] = true;
                }

            }
        }
    }

    return ret;
}

int main(void){
    fastio;
    int N, M; cin >> N >> M;

    // input ladders, snakes data
    vector<int> jumpData(MAXN+1);
    for(int i = 0; i < N + M; i++){
        int x, y; cin >> x >> y;
        jumpData[x] = y;
    }

    const int start = 1;
    int ans = bfs(jumpData, start);

    cout << ans << '\n';

    return 0;
}