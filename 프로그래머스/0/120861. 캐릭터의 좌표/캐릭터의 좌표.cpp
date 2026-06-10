#include <bits/stdc++.h>

#define DIR 4

using namespace std;
using Pos = pair<int, int>;

map<string, int> direction = 
{
    make_pair("up", 0),
    make_pair("right", 1),
    make_pair("down", 2),
    make_pair("left", 3)
};

int dx[DIR] = {0, 1, 0, -1};
int dy[DIR] = {1, 0, -1, 0};
int halfW, halfH;

bool InRange(int x, int y)
{
    return -halfW <= x && x <= halfW && -halfH <= y && y <= halfH;
}

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    
    halfW = board[0] / 2;
    halfH = board[1] / 2;
    
    Pos pos = make_pair(0, 0);
    for(const string& input : keyinput)
    {
        int dir = direction[input];
        int nx = pos.first + dx[dir];
        int ny = pos.second + dy[dir];
        if(InRange(nx, ny))
        {
            pos = make_pair(nx, ny);
        }
    }
    
    answer = {pos.first, pos.second};
    
    return answer;
}