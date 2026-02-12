#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<vector<int>> matrix;

int bfs(int start_pos, int N){
    vector<bool> visited(N+1);

    int visitedN = 0;

    queue<pair<int, int>> q;
    visited[start_pos] = true;
    q.push({start_pos, 0});
    visitedN++;

    int sum = 0;
    while(!q.empty()){
        pair<int, int> p = q.front(); q.pop();
        int curPos = p.first;
        int dist = p.second;
        
        for(int i = 1; i <= N; i++){
            if(matrix[curPos][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push({i, dist+1});
                visitedN++;
                sum += dist+1;

                // cout << "i: " << i << " cnt " << dist+1 << '\n';
            }
        }
    }

    return sum;
}

int main(void){
    fastio;
    int N, M; cin >> N >> M;

    matrix.resize(N+1, vector<int>(N+1));
    for(int i = 0; i < M; i++){
        int s, t;
        cin >> s >> t;
        matrix[s][t] = 1;
        matrix[t][s] = 1;
    }

    vector<int> kevinList(N+1);
    for(int i = 1; i <= N; i++){
        int kevinN = bfs(i, N);
        kevinList[i] = kevinN;
    }

    int ans = min_element(kevinList.begin()+1, kevinList.end()) - kevinList.begin();

    // for(int elem : kevinList){
    //     cout << elem << ' ';
    // }
    // cout << '\n';

    cout << ans << '\n';

    return 0;
}