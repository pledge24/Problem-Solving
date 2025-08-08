#include <bits/stdc++.h>

#define MAXN 100

using namespace std;
using Matrix = vector<vector<bool>>;
using Pos = pair<int, int>;

struct Robot
{
    Pos curPos;
    queue<Pos> dstList;
    bool finished = false;
};

// "자동 운송 시스템"
// 1. 2차원 배열의 좌표로 표현되는 n개의 포인트가 존재 (최대 n)
// 2. 로봇은 m개의 포인트로 구성된 운송 경로를 순서대로 방문.
// 3. x대의 로봇이 0초에 동시에 출발. 1초마다 "상하좌우" 1칸씩 이동.
// 4. 로봇은 항상 최단 경로로 다음 포인트로 이동하며, 최단 경로가 여러 개면 "상하" 이동이 "좌우" 보다 우선시 된다.
// 5. 로봇이 마지막 포인트에 도달하면, 물류 센터를 벗어난다.(단, 벗어나는 경로 고려 X)

// => 로봇끼리 충돌하는 상황이 총 몇 번 발생하는가?
// 충돌 판정
// - "충돌한 로봇 대수와 상관없이" 특정 시간에 충돌한 칸의 개수로 측정한다.

void Simulate(vector<Robot>& v1, int& answer){
    
    map<Pos, int> m1;
    
    // move all robots
    for(Robot& robot : v1){
        // skip
        if(robot.finished == true)
            continue;
        
        Pos& curPos = robot.curPos;
        Pos& dst = (robot.dstList).front();
        
        int dx = dst.first - curPos.first;
        int dy = dst.second - curPos.second;
        
        if(abs(dx) > 0)
            curPos.first += (dx > 0) ? 1 : -1;
        else
            curPos.second += (dy > 0) ? 1 : -1;
        
        // 로봇의 위치를 저장
        m1[robot.curPos]++;
        
        if(curPos == dst){
            (robot.dstList).pop();
            
            if((robot.dstList).empty()){
                robot.finished = true;
            }          
        }
    }
    
    for(auto elem : m1){
        answer += elem.second > 1;
        // cout << "Pos: (" << elem.first.first << ", " << elem.first.second << ") " << elem.second << '\n';
    }
    cout << '\n';
    
    
}

// 2 <= point <= 100
// routes : 경로 개수(=로봇 개수) -> [src, dstList]로 표현됨. 1부터 시작
int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    // Init
    vector<Robot> v1(routes.size());
    map<Pos, int> m1; // conflict check
    for(int i = 0; i < routes.size(); i++){
        Robot& robot = v1[i];
        vector<int>& route = routes[i];
        
        for(int pointNo : route){
            vector<int>& pos = points[pointNo-1];
            (robot.dstList).push(make_pair(pos[0], pos[1]));
        }

        // Set curPos
        Pos src = (robot.dstList).front(); (robot.dstList).pop();
        robot.curPos = src;
        
        m1[src]++;
    }
    
    for(auto elem : m1){
        answer += elem.second > 1;
    }
    
    int t = 0;
    while(true){
        // cout << "t: " << t << " conflicts: " << answer << '\n';
        
        bool AllFinished = all_of(v1.begin(), v1.end(), [](Robot r){
            return r.finished == true;
        });
        
        if(AllFinished == true)
            break;
        
        Simulate(v1, answer);
        
        t++;
    }
    
    return answer;
}