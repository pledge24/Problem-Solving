#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int64 solution(vector<int> sequence) {
    int64 answer = 0;
    
    int N = sequence.size();
    vector<pair<int64, int64>> dp(N); // end+1, end-1
    
    // init
    dp[0] = make_pair(max(sequence[0], 0), max(-sequence[0], 0));
    answer = max({dp[0].first, dp[0].second, int64(0)});
    for(int i = 1; i < N; i++){
        int64 num = sequence[i];
        
        int64 endPlus = max(dp[i-1].second + num, int64(0));
        int64 endMinus = max(dp[i-1].first + (-num), int64(0));
        
        dp[i] = make_pair(endPlus, endMinus);
        
        answer = max({answer, endPlus, endMinus});
    }
    
    return answer;
}