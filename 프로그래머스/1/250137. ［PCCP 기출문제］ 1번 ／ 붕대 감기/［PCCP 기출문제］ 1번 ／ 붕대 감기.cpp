#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int castTime = bandage[0];
    int tickHeal = bandage[1];
    int extraHeal = bandage[2];
    
    int prevAtkTime = 0;
    int curHP = health;
    for(int i = 0; i < attacks.size(); i++){
        int atkTime = attacks[i][0];
        int atkDmg = attacks[i][1];
        
        int tick = atkTime - prevAtkTime - 1;
        int totalHeal = tickHeal*tick + extraHeal*(tick / castTime);
        
        curHP = min(health, curHP + totalHeal) - atkDmg;
        
        // cout << "curHP: " << curHP << '\n';
        
        if(curHP <= 0)
            break;
        
        prevAtkTime = atkTime;
    }
    
    answer = curHP > 0 ? curHP : -1;
    
    return answer;
}