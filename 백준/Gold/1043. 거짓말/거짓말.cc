#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void bfs(vector<bool>& visited, int N, vector<int> &people, vector<vector<bool>> &matrix){

    queue<int> q;
    for(int elem: people){
        q.push(elem);
        visited[elem] = true;
    }

    while(!q.empty()){
        int personId = q.front(); q.pop();
        for(int i = 1; i <= N; i++){
            // 진실이 퍼질수 있는 신입인 경우
            if(matrix[personId][i] && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }

    return;
}

int main(void){
    fastio;
    // 1
    int N, M; cin >> N >> M;

    // 2
    int peopleN; cin >> peopleN;
    vector<int> people;
    for(int i = 0; i < peopleN; i++){
        int num; cin >> num;
        people.push_back(num);
    }

    vector<vector<bool>> matrix(N+1, vector<bool>(N+1));
    vector<vector<int>> v1(M);
    // 3~
    for(int i = 0; i < M; i++){
        int partyN; cin >> partyN;
        v1[i].resize(partyN);
        for(int n = 0; n < partyN; n++){
            cin >> v1[i][n];
        }

        for(int x = 0; x < partyN; x++){
            for(int y = x+1; y < partyN; y++){
                int s = v1[i][x];
                int t = v1[i][y];

                matrix[s][t] = true;
                matrix[t][s] = true;
            }
        }
    }

    vector<bool> visited(N + 1);
    bfs(visited, N, people, matrix);

    int ans = 0;
    for(int i = 0; i < M; i++){
        bool can = true;
        for(int elem : v1[i]){
            if(visited[elem]){
                can = false;
                break;
            }
        }
        
        if(can){
            // cout << i << '\n';
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}