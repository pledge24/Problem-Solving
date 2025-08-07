#include <bits/stdc++.h>

using namespace std;

// diff: 퍼즐 난이도
// time_cur: 현재 소요 시간
// time_prev: 이전 퍼즐 소요 시간
// level: 숙련도

// 목표) n개의 퍼즐을 제한 시간 내에 풀자.
// 적당한 난이도 => time_cur 시간에 해결
// 높은 난이도 => diff-level번 틀림. 틀릴때마다 (time_cur + time_prev) 시간 사용
//           => 틀린 다음 time_cur 시간에 해결 
// 

// 1 <= diffs <= 300,000
// -> 최대 level -> 300,000

// 전체 제한 시간 "limit"가 있음.
// => 전체 제한 시간 내에 모든 문제를 풀기위한 최소 숙련도(level)은?

bool IsTimeOver(vector<int>& diffs, vector<int>& times, long long limit, int level){
    long long total_time = 0;
    int N = diffs.size();
    
    total_time += times[0];
    for(int i = 1; i < N; i++){
        // limit과 total_time이 동일했을때 처리는 어떻게?
        if(total_time > limit){
            break;
        }
        
        int curDiff = diffs[i];        
        int wrongN = curDiff > level ? curDiff - level : 0;
        
        total_time += wrongN * (times[i-1] + times[i]) + times[i];
    }
    
    return total_time > limit;
}

// lower_bound 문제
void LowerBound(vector<int>& diffs, vector<int>& times, long long limit, int& answer){
    int maxLevel = 300'000;
    
    int low = 1;
    int high = maxLevel+1;
    
    while(low < high){
        int mid = (low + high) / 2;
        
        if(IsTimeOver(diffs, times, limit, mid)){
            low = mid + 1;
        }
        else{
            high = mid;
        }
    }
    
    answer = low;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    LowerBound(diffs, times, limit, answer);
        
    return answer;
}