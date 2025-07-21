#include <bits/stdc++.h>
using namespace std;

// 모든 가능한 N/2 크기의 조합을 생성
void generateCombinations(int n, int k, int start, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == k) {
        result.push_back(current);
        return;
    }
    
    for (int i = start; i < n; i++) {
        current.push_back(i);
        generateCombinations(n, k, i + 1, current, result);
        current.pop_back();
    }
}

// 주어진 주사위 조합의 모든 가능한 점수 합을 계산
vector<int> calculateScores(const vector<vector<int>>& dice, const vector<int>& combination) {
    vector<int> scores;
    
    // 재귀적으로 모든 가능한 조합 생성
    function<void(int, int)> dfs = [&](int idx, int sum) {
        if (idx == combination.size()) {
            scores.push_back(sum);
            return;
        }
        
        for (int face : dice[combination[idx]]) {
            dfs(idx + 1, sum + face);
        }
    };
    
    dfs(0, 0);
    sort(scores.begin(), scores.end());
    return scores;
}

vector<int> solution(vector<vector<int>> dice) {
    int n = dice.size();
    int k = n / 2;
    
    // 모든 가능한 N/2 크기의 조합 생성
    vector<vector<int>> combinations;
    vector<int> current;
    generateCombinations(n, k, 0, current, combinations);
    
    int maxWins = -1;
    vector<int> bestCombination;
    
    // 각 조합에 대해 승률 계산
    for (const auto& comb1 : combinations) {
        // 상대방 조합 구성
        vector<bool> used(n, false);
        for (int idx : comb1) {
            used[idx] = true;
        }
        
        vector<int> comb2;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                comb2.push_back(i);
            }
        }
        
        // 각 조합의 모든 가능한 점수 계산
        vector<int> scores1 = calculateScores(dice, comb1);
        vector<int> scores2 = calculateScores(dice, comb2);
        
        // 승리 횟수 계산
        int wins = 0;
        for (int score1 : scores1) {
            // score2에서 score1보다 작은 값의 개수를 찾음
            wins += lower_bound(scores2.begin(), scores2.end(), score1) - scores2.begin();
        }
        
        if (wins > maxWins) {
            maxWins = wins;
            bestCombination = comb1;
        }
    }
    
    // 1-based 인덱스로 변환
    for (int& idx : bestCombination) {
        idx++;
    }
    
    return bestCombination;
}