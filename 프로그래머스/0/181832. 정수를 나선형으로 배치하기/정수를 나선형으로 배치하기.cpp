#include <bits/stdc++.h>

#define DIR 4

int dx[DIR] = {0, 1, 0, -1};
int dy[DIR] = {1, 0, -1, 0};

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, -1));
    
    int moveN = 0;
    int num = 1;
    int x = 0;
    int y = 0;
    int d = 0;
    answer[0][0] = 1;
    do
    {
        moveN = 0;
        while(true)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if(!(0 <= nx && nx < n && 0 <= ny && ny < n) || answer[nx][ny] >= 0)
                break;
            
            x += dx[d];
            y += dy[d];
            answer[x][y] = ++num;
            moveN++;
        }
        
        d = (d + 1) % DIR;
    }
    while(moveN > 0);
    
    return answer;
}