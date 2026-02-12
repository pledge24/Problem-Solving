#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void bfs(vector<vector<int>> &matrix, int N){

    for(int i = 0; i < N; i++){
        vector<bool> visited(matrix.size());

        queue<int> q;
        q.push(i);

        // i 정점에서 갈 수 있는 모든 정점을 업데이트
        while(!q.empty()){
            int curVtx = q.front(); q.pop();

            for(int j = 0; j < N; j++){
                // 방문하지 않은 정점들 중(나 포함) 이동 가능한 정점인 경우
                if(!visited[j] && matrix[curVtx][j]){
                    visited[j] = true;
                    matrix[i][j] = 1;
                    q.push(j);
                }
            }
        }
    }   

}

int main(void){
    fastio;

    int N; cin >> N;
    vector<vector<int>> matrix;
    matrix.resize(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> matrix[i][j];
        }
    }

    bfs(matrix, N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}