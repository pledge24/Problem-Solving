#include <bits/stdc++.h>

#define WEEK 7
#define WEEKEND 6

using namespace std;

bool canReward(int deadLine, vector<int>& timeLog, int startday){
    int N = timeLog.size();
    int day = startday;
    for(int i = 0; i < N; i++){
        // 주말(토요일, 일요일)은 통과  
        if(day >= WEEKEND){
            day = (day + 1) > WEEK ? 1 : (day + 1);
            continue;
        }
            
        if(timeLog[i] > deadLine)
            return false;
        
        day = (day + 1) > WEEK ? 1 : (day + 1);
    }
    
    return true;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    int N = schedules.size();
    for(int i = 0; i < N; i++){
        int minute = (schedules[i] % 100) + 10;       
        int hours = schedules[i] - (schedules[i] % 100);
        
        int deadLine = 0;
        if(minute < 60)
            deadLine = schedules[i] + 10;
        else
            deadLine = (hours+100) + minute % 60;

        vector<int>& timeLog = timelogs[i];

        if(canReward(deadLine, timeLog, startday))
            answer++;
    }
    
    return answer;
}