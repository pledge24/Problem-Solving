#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;

int N, M; 
int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

int bfs(vector< vector<char> > &matrix, pair<int, int> startPos, bool flag){
    if(!flag)
        return 0;
    
    queue< pair<int, int> > q;
    q.push(startPos);
    matrix[startPos.first][startPos.second] = 'X';

    int cnt = 0;
    while(!q.empty()){
        pair<int, int> curPos = q.front(); q.pop();

        for(int i = 0; i < DIR; i++){
            int nx = curPos.first + dx[i];
            int ny = curPos.second + dy[i];

            if(inRange(nx, ny) && matrix[nx][ny] != 'X'){
                // 사람을 만나면 카운트 증가.
                if(matrix[nx][ny] == 'P')
                    cnt++;

                q.push({nx, ny});
                matrix[nx][ny] = 'X';
            }

        }
    }

    return cnt;
}

int main(void){
    fastio;
    cin >> N >> M;

    vector< vector<char> > matrix;
    pair<int, int> startPos;
    matrix.resize(N, vector<char>(M));
    bool flag = false;
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        for(int j = 0; j < s.length(); j++){
            matrix[i][j] = s[j];

            if(s[j] == 'I'){
                startPos = {i, j};
                flag = true;
            }
        }
    }

    int ans = bfs(matrix, startPos, flag);

    if(ans == 0){
        cout << "TT" << '\n';
    }
    else{
        cout << ans << '\n';
    }

    return 0;
}