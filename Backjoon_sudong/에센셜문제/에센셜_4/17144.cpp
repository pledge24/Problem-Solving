#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4
#define OUT

using namespace std;
using Pos = pair<int,int>;

int R, C;
int dx[DIR] = {0, 1, 0, -1};
int dy[DIR] = {1, 0, -1, 0};

bool inRange(int x, int y){
    return 0 <= x && x < R && 0 <= y && y < C;
}

void getNextPos(Pos &pos, int& dir, pair<int, int> rot[DIR]){

    for(dir; dir < DIR;){
        int nx = pos.first + rot[dir].first;
        int ny = pos.second + rot[dir].second;

        // cout << nx << " " << ny << '\n';
        if(inRange(nx, ny)){
            pos = make_pair(nx, ny);
            break;
        }
        else{
            dir++;
        }

    }

    return;
}

void printMatrix(vector<vector<int>> &matrix){
    cout << '\n';
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void simulate(vector<vector<int>> &matrix, vector<pair<int,int>> &acPos){

    // distribute
    queue<pair<Pos, int>> dirtData;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){         
            if(matrix[i][j] > 0)
                dirtData.push(make_pair(make_pair(i, j), matrix[i][j]));
        }
    }

    while(!dirtData.empty()){
        pair<Pos, int> curData = dirtData.front(); dirtData.pop();
        Pos curPos = curData.first;
        int dirt = curData.second;

        // 확산 가능한 위치를 찾는다.
        vector<bool> canDistribute(DIR); 
        int cnt = 0;
        for(int i = 0; i < DIR; i++){
            int nx = curPos.first + dx[i];
            int ny = curPos.second + dy[i];

            if(inRange(nx, ny) && matrix[nx][ny] != -1){
                canDistribute[i] = true;
                cnt++;
            }
        }

        int distrubeDirt = dirt / 5;
        int minusDirt = (distrubeDirt * cnt);

        // 현재 위치의 먼지 확산 적용
        matrix[curPos.first][curPos.second] -= minusDirt;
        for(int i = 0; i < DIR; i++){
            int nx = curPos.first + dx[i];
            int ny = curPos.second + dy[i];

            if(canDistribute[i]){
                matrix[nx][ny] += distrubeDirt;
            }
        }
    }

    // printMatrix(matrix);

    // circulate
    pair<int, int> ccw[DIR] = { make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1), make_pair(1, 0),};
    pair<int, int> cw[DIR] = { make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0),};

    Pos upPos = acPos[0];
    Pos downPos = acPos[1];

    // 반시계 방향 순환
    {
        int curDir = 0;
        int prevDirt = 0;
        Pos nextPos = upPos;
        getNextPos(OUT nextPos, OUT curDir, ccw); 
    
        while(matrix[nextPos.first][nextPos.second] != -1){
            swap(prevDirt, matrix[nextPos.first][nextPos.second]);
            getNextPos(nextPos, OUT curDir, ccw);
        }
    }

    // 시계 방향 순환
    {
        int curDir = 0;
        int prevDirt = 0;
        Pos nextPos = downPos;
        getNextPos(OUT nextPos, OUT curDir, cw); 
    
        while(matrix[nextPos.first][nextPos.second] != -1){
            swap(prevDirt, matrix[nextPos.first][nextPos.second]);
            getNextPos(nextPos, OUT curDir, cw);
        }
    }

    // printMatrix(matrix);
}


int main(void){
    fastio;
    int T; cin >> R >> C >> T;

    vector<vector<int>> matrix(R, vector<int>(C));
    vector<pair<int,int>> acPos;
    // input Data.
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> matrix[i][j];

            if(matrix[i][j] == -1)
                acPos.push_back(make_pair(i, j));
        }
    }

    for(int i = 0; i < T; i++){
        simulate(matrix, acPos);
    }

    int ans = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            ans += max(0, matrix[i][j]);
        }
    }

    cout << ans << '\n';

    return 0;
}