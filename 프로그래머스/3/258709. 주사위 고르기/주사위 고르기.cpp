#include <bits/stdc++.h>

#define DICE_N 6

using namespace std;
using DiceCombi = vector<int>;
using ScoreList = vector<int>;

// 문제 설명) 
// 두 사람이 각각 n/2개의 주사위를 나눠가진다.
// 주어진 주사위를 굴려 나온 각 눈의 합이 높은 사람이 이긴다.(같으면 무승부)
// => 승리할 확률이 가장 높은 주사위 조합은?

// 10C5

void calcCombi(vector<vector<int>>& dice, map<DiceCombi, ScoreList>& final_DiceCombi){
    int N = dice.size();
    
    vector<map<DiceCombi, ScoreList>> DP(N);
    
    // init
    DP[0][DiceCombi{0}] = dice[0];
    
    for(int i = 1; i < N; i++){
        vector<int> curDice = dice[i];
        
        DP[i][DiceCombi{i}] = curDice;
        
        // 현재 다이스를 이전 조합에서 넣거나 넣지 않는다.(단, N/2는 넘어가도록 넣지는 않는다.)
        map<DiceCombi, ScoreList>& m1 = DP[i-1];
        for(auto elem : m1){
            DiceCombi curCombi = elem.first;
            ScoreList curScoreList = elem.second;
            
            // 이전 조합
            DP[i][curCombi] = curScoreList;
            
            if(curCombi.size() >= N/2)
                continue;
            
            DiceCombi nextCombi = curCombi;
            nextCombi.push_back(i);
            for(auto score : curScoreList){ /* 이전 주사위 눈의 합 리스트 */
                for(auto curDiceScore : curDice){ /* 정확히 6번 돈다.*/
                    // cout << "score : " << score << " curDiceScore: " << curDiceScore << '\n';
                    DP[i][nextCombi].push_back(score + curDiceScore);
                }
            }
            
            // if(curCombi.size() == N/2){
            //     final_DiceCombi[curCombi] = DP[i][curCombi];
            //     sort(final_DiceCombi[curCombi].begin(), final_DiceCombi[curCombi].end());
            // }
        }
        
        for(auto p1 : DP[N-1]){
            if(p1.first.size() == N/2){
                sort(p1.second.begin(), p1.second.end());
                final_DiceCombi.insert(p1);
            }
                
        }
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    
    map<DiceCombi, ScoreList> final_DiceCombi;
    if(dice.size() == 2){
        final_DiceCombi[DiceCombi{0}] = dice[0];
        sort(final_DiceCombi[DiceCombi{0}].begin(), final_DiceCombi[DiceCombi{0}].end());
        final_DiceCombi[DiceCombi{1}] = dice[1];
        sort(final_DiceCombi[DiceCombi{1}].begin(), final_DiceCombi[DiceCombi{1}].end());
    }
    else
        calcCombi(dice, final_DiceCombi);
    
    // cout << "final_DiceCombi: " << final_DiceCombi.size() << '\n';
    // for(auto p1 : final_DiceCombi){
    //     for(int elem : p1.first)
    //         cout << elem << ' ';
    //     cout << ":: ";
    //     for(int elem : p1.second)
    //         cout << elem << ' ';
    //     cout << '\n';
    // }
    
    // 가장 승리 확률이 높은 조합을 찾는다.
    DiceCombi maxWinsCombi;
    int maxWins = -1;
    for(auto p1 : final_DiceCombi){
        DiceCombi curCombi = p1.first;
        DiceCombi otherCombi;
        
        vector<bool> haveDice(dice.size());
        for(int idx : curCombi)
            haveDice[idx] = true;
        
        for(int i = 0; i < dice.size(); i++){
            if(haveDice[i] == false)
                otherCombi.push_back(i);
        }
        
        ScoreList& scores = final_DiceCombi[otherCombi];
        int total_wins = 0;
        for(int diceScore : p1.second){
            total_wins += lower_bound(scores.begin(), scores.end(), diceScore) - scores.begin();
        }
        
        // for(auto elem : curCombi)
        //     cout << elem << ' ';
        // cout << ": ";
        // cout << "total_wins: " << total_wins << '\n';
        if(maxWins <= total_wins){
            maxWins = total_wins;
            maxWinsCombi = curCombi;
        }
    }
    
    for(auto elem : maxWinsCombi){
        answer.push_back(elem+1);
        sort(answer.begin(), answer.end());
    }
    
    return answer;
}