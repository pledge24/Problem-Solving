#include <bits/stdc++.h>

#define DIR 4

using namespace std;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

int R, C;

bool inRange(int x, int y){
    return 0 <= x && x < R && 0 <= y && y < C;
}

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    R = board.size();
    C = board[0].size();
    
    string color = board[h][w];
    
    for(int i = 0; i < DIR; i++){
        int nx = h + dx[i];
        int ny = w + dy[i];
        if(inRange(nx, ny) && board[nx][ny] == color)
            answer++;
    }
    
    return answer;
}