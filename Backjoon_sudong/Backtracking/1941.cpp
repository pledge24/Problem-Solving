#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 3

using namespace std;
using Matrix = vector<vector<char>>;
using Pos = pair<int, int>;

int dx[DIR] = {0, 1, 0};    /* 위쪽 방향 이동 제외*/
int dy[DIR] = {1, 0, -1};

int totalCnt = 0;
const int M = 7;    /* 칠공주 인원수 */
const int N = 5;    /* matrix 가로 세로 길이 */
const int MAXY = 3; /* 최대 임도연파 수 */

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

void Backtracking(Matrix& matrix, set<Pos> peopleSet, int cntS, int cntY){
    if(peopleSet.size() == M){
        totalCnt++;
        return;
    }

    for(Pos pos : peopleSet){
        for(int i = 0; i < DIR; i++){
            int nx = dx[i] + pos.first;
            int ny = dy[i] + pos.second;
    
            if(inRange(nx, ny)){
                Pos curPos = make_pair(nx, ny);
                /* 이미 포함된 인원인 경우 패스 */
                if(peopleSet.find(curPos) != peopleSet.end())
                    continue;
    
                /* 임도연파 최대인원 초과 */
                if((matrix[nx][ny] == 'Y') + cntY > MAXY)
                    continue;
    
                peopleSet.insert(curPos);
                Backtracking(matrix, peopleSet, cntS + (matrix[nx][ny] == 'S'), cntY + (matrix[nx][ny] == 'Y'));
                peopleSet.erase(curPos);
            }
    
    
        }
    }
    
    
}

int main(void){
    fastio;
    Matrix matrix(N, vector<char>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < N*N; i++){
        set<Pos> peopleSet;
        int startR = i / N;
        int startC = i % N;
        int cnt = 0;

        peopleSet.insert(make_pair(startR, startC));
        Backtracking(matrix, peopleSet, matrix[startR][startC] == 'S', matrix[startR][startC] == 'Y');
    }


    cout << totalCnt << '\n';

    return 0;
}