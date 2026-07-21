#include <bits/stdc++.h>

#define DIV 1'000'000'007LL

using namespace std;
using Pos = pair<int, int>;
using int64 = long long;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<int64>> dp(m, vector<int64>(n));
    for(vector<int> p : puddles)
    {
        int r = p[0] - 1;
        int c = p[1] - 1;
        dp[r][c] = -1;    
    }
    
    // Function InRange
    auto IsValid = [m, n, &dp](int x, int y){
        if(0 <= x && x < m && 0 <= y && y < n)
        {
            if(dp[x][y] != -1)
                return true;
        }
        return false;
    };
    
    // Fill DP.
    dp[0][0] = 1;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dp[i][j] == -1)
                continue;
            
            int64 up = IsValid(i-1, j) ? dp[i-1][j] : 0;
            int64 left = IsValid(i, j-1) ? dp[i][j-1] : 0;
            
            dp[i][j] = std::max(dp[i][j], up + left) % DIV;
        }
    }
    
    // DEBUG Print
    // for(int i = 0; i < m; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    answer = dp[m-1][n-1];
    
    return answer;
}