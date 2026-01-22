#include <bits/stdc++.h>

using namespace std;
using Pos = pair<int, int>;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool Move(Pos& pos, char dir)
{
    int idx = -1;
    if(dir == 'U')
        idx = 0;
    else if(dir == 'D')
        idx = 1;
    else if(dir == 'R')
        idx = 2;
    else 
        idx = 3;
    
    int nx = pos.first + dx[idx];
    int ny = pos.second + dy[idx];
    
    bool inRange = -5 <= nx && nx <= 5 && -5 <= ny && ny <= 5;
    if(inRange)
    {
        pos.first = nx;
        pos.second = ny;
        
        return true;
    }
    
    return false;
}

int solution(string dirs) {
    int answer = 0;
    
    set<pair<Pos, Pos>> s;
    
    Pos curPos = make_pair(0, 0);
    for(char c : dirs)
    {
        Pos prevPos = curPos;
        if(Move(curPos, c))
        {
            pair<Pos, Pos> p1 = make_pair(curPos, prevPos);
            pair<Pos, Pos> p2 = make_pair(prevPos, curPos);

            if(s.find(p1) == s.end() && s.find(p2) == s.end())
                s.insert(p1);

            // cout << curPos.first << " " << curPos.second << '\n';
        }
    }
    
    answer = s.size();
    
    return answer;
}