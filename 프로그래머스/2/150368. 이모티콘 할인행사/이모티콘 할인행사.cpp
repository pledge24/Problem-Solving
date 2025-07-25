#include <bits/stdc++.h>

#define DISCOUNT_N 4

using namespace std;

int discounts[DISCOUNT_N] = {10, 20, 30, 40};

// n명의 카카오톡 사용자들에게 m개의 이모티콘을 할인하여 판매 (m = {10%, 20%, 30%, 40%})

// 사용자 행동 패턴
// 1) X% 이상 할인하는 이모티콘은 다 산다. 
// 2) 총 비용이 Y원 이상이면, 이모티콘 플러스 서비스에 가입

// => "이모티콘 플러스 서비스" 가입자 수를 최대한 늘려라. 그리고 판매액을 늘려라.

// 각 이모티콘 할인률은 모든 사용자가 같다.
// 최대 사용자수(users) == 100
// 최대 이모티콘 개수 == 7
// 4^7 => 2^14 => 1000*16 => 16,000
// 서비스 가입 시 구매 비용 0원

void DfsUtil(vector<vector<int>>& users, vector<int>& emoticons, vector<int>& sequence, pair<int, int>& res){
    // 종료 조건.
    if(sequence.size() >= emoticons.size()){
        
        pair<int, int> candidate;
        for(vector<int>& user : users){
            int userDiscount = user[0];
            int userCost = user[1];
            
            int cost = 0;
            
            // 현재 유저가 산 이모티콘의 금액을 계산
            for(int i = 0; i < emoticons.size(); i++){
                int discountIdx = sequence[i]; // 이모티콘 할인률
                
                // 원하는 할인률보다 낮으면 안 산다.
                if(discounts[discountIdx] < userDiscount){
                    continue;
                }
                
                float percent = discounts[discountIdx];
                cost += emoticons[i] * (1.0 - (percent / 100.0));
            }
            
            // cout << "userCost: " << userCost << '\n';
            
            // 이모티콘 구매액이 유저 금액을 넘으면 서비스 가입
            if(cost >= userCost){
                candidate.first++;
            }
            else{
                candidate.second += cost;
            }
        }
        
        res = max(res, candidate);
        
        return;
    }    
    
    for(int i = 0; i < DISCOUNT_N; i++){
        sequence.push_back(i);
        DfsUtil(users, emoticons, sequence, res);
        sequence.pop_back();
    }
}

void Dfs(vector<vector<int>>& users, vector<int>& emoticons, vector<int>& answer){
    vector<int> sequence;
    pair<int, int> res = make_pair(0, 0); // 가입자 수, 매출액
    
    DfsUtil(users, emoticons, sequence, res);   
    
    answer = {res.first, res.second};
    
    return;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    Dfs(users, emoticons, answer);
    
    return answer;
}