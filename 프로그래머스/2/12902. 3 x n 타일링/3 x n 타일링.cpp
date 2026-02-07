#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

const int64 DIV = 1'000'000'007;

int solution(int n) {
    int answer = 0;
    vector<int64> dp(5001);
    
    // Init
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    
    int64 sum = 0;
    
    // Process
    for(int i = 3; i < dp.size(); i++)
    {
        if(i % 2 == 1)
        {
            dp[i] = 0;
            continue;
        }
        
        dp[i] = (dp[i-2] * 3 + sum * 2 + 2) % DIV;
        sum += dp[i-2]; // 과거 특수 패턴 누적
    }
    
    answer = dp[n];
    
    return answer;
}