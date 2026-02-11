#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    dp[1] = vector<int>(n+1, 1);
    for(int i = 2; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            int accu = 0;
            for(int x = 1; x <= j; x++)
            {
                accu += dp[i-1][x];
            }
            dp[i][j] = accu;
        }
    }
    
    answer = dp[n][n];
    
    return answer;
}