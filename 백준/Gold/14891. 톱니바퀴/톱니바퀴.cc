#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int GEAR_N = 4;

bool inRange(int x){
    return 0 <= x && x < GEAR_N;
}

void rotateCW(vector<bool>& visited, vector<deque<int>>& gears, int gearNo);
void rotateCCW(vector<bool>& visited, vector<deque<int>>& gears, int gearNo);

void rotateCW(vector<bool>& visited, vector<deque<int>>& gears, int gearNo){    
    visited[gearNo] = true;
       
    deque<int>& curGear = gears[gearNo];
    int dir3 = curGear[2];
    int dir9 = curGear[6];

    // rotate clockwise
    curGear.push_front(curGear.back());
    curGear.pop_back();
    
    // leftSide gear
    if(inRange(gearNo-1) && !visited[gearNo-1] && gears[gearNo-1][2] != dir9)
        rotateCCW(visited, gears, gearNo-1);

    // rightSide gear
    if(inRange(gearNo+1) && !visited[gearNo+1] && gears[gearNo+1][6] != dir3)
        rotateCCW(visited, gears, gearNo+1);
    
}

void rotateCCW(vector<bool>& visited, vector<deque<int>>& gears, int gearNo){
    visited[gearNo] = true;
       
    deque<int>& curGear = gears[gearNo];
    int dir3 = curGear[2];
    int dir9 = curGear[6];

    // rotate counter-clockwise
    curGear.push_back(curGear.front());
    curGear.pop_front();
    
    // leftSide gear
    if(inRange(gearNo-1) && !visited[gearNo-1] && gears[gearNo-1][2] != dir9)
        rotateCW(visited, gears, gearNo-1);

    // rightSide gear
    if(inRange(gearNo+1) && !visited[gearNo+1] && gears[gearNo+1][6] != dir3){
        rotateCW(visited, gears, gearNo+1);
    }
}

int main(void){
    fastio;
    vector<deque<int>> gears(GEAR_N);
    for(int i = 0; i < GEAR_N; i++){
        string str; cin >> str;
        for(char c : str)
            gears[i].push_back(c - '0');
    }

    int N; cin >> N;
    for(int i = 0; i < N; i++){
        int gearNo, rotateType; cin >> gearNo >> rotateType;
        vector<bool> visited(GEAR_N);
        if(rotateType == 1 /* 시계 방향 회전 */){
            rotateCW(visited, gears, gearNo-1);
        }
        else{
            rotateCCW(visited, gears, gearNo-1);
        }

        // print Gear
        // for(auto gear : gears){
        //     for(int elem : gear)
        //         cout << elem;
        //     cout << '\n';
        // }
        // cout << '\n';
    }

    int score = 0;
    for(int i = 0; i < GEAR_N; i++){
        score += gears[i].front()*pow(2, i);       
    }

    cout << score << '\n';

    return 0;
}