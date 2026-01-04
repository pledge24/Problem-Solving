#include <bits/stdc++.h>

using namespace std;

enum Direction
{
    TOP,
    BOTTOM,
    LEFT,
    RIGHT,
};

const int INF = 1'000'000'000;
int M, N;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int GetDistance(int x1, int y1, int x2, int y2, Direction dir)
{
    int unit_vx = x2 - x1 != 0 ? (x2 - x1)/abs(x2 - x1) : 0;
    int unit_vy = y2 - y1 != 0 ? (y2 - y1)/abs(y2 - y1) : 0;
    if(unit_vx == 0 || unit_vy == 0)
    {
        if(unit_vx == dx[dir] && unit_vy == dy[dir])
            return INF;
    }
    
    switch(dir)
    {
    case TOP:
        {
            y1 += 2 * (N - y1);
            break;
        }
    case BOTTOM:
        {
            y1 = -y1;
            break;
        }
    case LEFT:
        {
            x1 = -x1;
            break;
        }
    case RIGHT:
        {
            x1 += 2 * (M - x1);
            break;
        }
    }
    
    int vx = x1-x2;
    int vy = y1-y2;
    
    // cout << vx << " " << vy << '\n';
    
    return vx*vx + vy*vy;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    M = m;
    N = n;
    
    for(vector<int>& ball : balls)
    {
        int endX = ball[0];
        int endY = ball[1];
        
        // 4방향을 전부 구한다.
        int top = GetDistance(startX, startY, endX, endY, TOP);
        int bottom = GetDistance(startX, startY, endX, endY, BOTTOM);
        int left = GetDistance(startX, startY, endX, endY, LEFT);
        int right = GetDistance(startX, startY, endX, endY, RIGHT);
        
        // cout << top << " " << bottom << " " << left << " " << right << '\n';
        
        int minDist = min({top, bottom, left, right});
        answer.push_back(minDist);
    }
    
    return answer;
}