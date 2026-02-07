#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

const int64 DIV = 1'000'000'007;

int solution(int n) {
    int answer = 0;
    vector<int64> dp(n+1);
    
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % DIV;
    }
    
    answer = dp[n];
                     
    return answer;
}