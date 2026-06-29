#include <bits/stdc++.h>

#define INF 100'000'000

using namespace std;

int solution(int hp) {
    int answer = 0;
    
    vector<int> dp(max(hp+1, 6), INF);
    dp[0] = 0;
    dp[1] = dp[3] = dp[5] = 1;
    for(int i = 1; i <= hp; i++)
    {
        if(i-1 >= 0)
            dp[i] = min(dp[i-1]+1, dp[i]); 
        if(i-3 >= 0)
            dp[i] = min(dp[i-3]+1, dp[i]);
        if(i-5 >= 0)
            dp[i] = min(dp[i-5]+1, dp[i]);
    }
    
    answer = dp[hp];
    
    return answer;
}