#include <bits/stdc++.h>

#define MAXSCORE 60
using namespace std;

// 블랙젝의 반대룰 "카운트 다운"
// 다트를 던져 점수를 얻고, 점수만큼 깎아서 정확히 0점을 만들자(넘어가면 실격)
// 숫자는 1~20, 점수는 X1, X2, X3, 50점이 있음
// -> 최소한의 다트로 점수를 만들때 싱글 또는 불을 가장 많이 맞춘 횟수는?
// minDart, sumCnt
vector<int> solution(int target) {
    vector<int> answer;
    
    vector<pair<bool, bool>> scoreData(MAXSCORE+1); // <득점 가능한 점수인가?, 싱글 또는 불인가?>
    for(int multiply = 1; multiply <= 3; multiply++){
        for(int i = 1; i <= 20; i++){
            scoreData[i*multiply].first = true;
            if(multiply == 1)
                scoreData[i*multiply].second = true;
        }
    }
    
    // Bull값 처리
    const int bullScore = 50;
    scoreData[bullScore] = make_pair(true, true);
    
    int N = target;
    vector<pair<int, int>> DP(max(N+1, MAXSCORE+1)); // <최소 다트, 싱글 + 불 개수>
    
    // init
    for(int score = 1; score <= MAXSCORE; score++){
        // 1. 원트로 얻을 수 없는 점수
        if(scoreData[score].first == false){
            DP[score] = make_pair(-1, -1);
            continue;
        }
        
        DP[score] = make_pair(1, scoreData[score].second == true);
    }
       
    for(int i = 21; i <= N; i++){
        // 이미 초기화로 얻은 점수는 통과
        if(DP[i].first > 0)
            continue;
        
        // 점수 i를 만드는데 최적값을 구한다.(scoreData를 순회하면서)
        for(int score = 1; score <= 60; score++){
            // 1. 다트를 던져서 얻을 수 없는 점수
            if(scoreData[score].first == false)
                continue;
            
            // 2. 이전 점수가 음수 또는 0인 경우
            if(i - score <= 0)
                break;
            
            // 3. 이전 점수에 도달한 적이 없는 경우
            if(DP[i - score] == make_pair(-1, -1))
                continue;
            
            pair<int, int> cand = DP[i - score];
            cand.first++;
            cand.second += scoreData[score].second == true;
                      
            if(DP[i].first <= 0)
                DP[i] = cand;           
            else if(cand.first < DP[i].first)
                DP[i] = cand;
            else if(cand.first == DP[i].first && cand.second > DP[i].second)
                DP[i] = cand;
        }
    }
    
    // for(int i = 1; i <= N; i++){
    //     cout << "i: " << i << " " << DP[i].first << " " << DP[i].second << '\n';
    // }
    answer = {DP[N].first, DP[N].second};
    
    return answer;
}