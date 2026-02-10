#include <bits/stdc++.h>

#define DIV 1'000'000'007

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    int moneyN = money.size();
    
    std::sort(money.begin(), money.end());
    vector<vector<int>> dp(moneyN+1, vector<int>(n+1));
    for(int i = 1; i <= moneyN; i++)
    {
        int value = money[i-1];
        dp[i][0] = 1;
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(value <= j)
            {
                dp[i][j] = (dp[i][j] + dp[i][j-value]) % DIV;
            }
        }
    }
    
//     for(int i = 0; i < dp.size(); i++)
//     {
//         for(int j = 0; j < dp[0].size(); j++)
//         {
//             cout << dp[i][j] << ' ';
//         }
//         cout << '\n';
//     }
    
    answer = dp[moneyN][n];
    
    return answer;
}