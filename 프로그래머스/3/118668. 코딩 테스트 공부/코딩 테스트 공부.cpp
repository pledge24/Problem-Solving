#include <bits/stdc++.h>

#define INF 100'000'000

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int maxAlp = alp;
    int maxCop = cop;
    
    // Find Max Point.
    for(vector<int> prob : problems)
    {
        maxAlp = max(maxAlp, prob[0]);
        maxCop = max(maxCop, prob[1]);
    }
    
    vector<vector<int>> dp(150+2, vector<int>(150+2, INF));
    dp[alp][cop] = 0;
    
    // DP
    for(int i = alp; i <= max(alp, maxAlp); i++)
    {
        for(int j = cop; j <= max(cop, maxCop); j++)
        {
            // Study Point.
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
            dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
            
            for(vector<int> prob : problems)
            {
                int alp_req = prob[0];
                int cop_req = prob[1];
                int alp_rwd = prob[2];
                int cop_rwd = prob[3];
                int cost = prob[4];
                
                if(i < alp_req || j < cop_req)
                    continue;
                
                int nextI = min(i + alp_rwd, maxAlp);
                int nextJ = min(j + cop_rwd, maxCop);
                
                dp[nextI][nextJ] = min(dp[nextI][nextJ], dp[i][j] + cost);
            }
        }
    }
    
    answer = dp[maxAlp][maxCop];
    
    // for(int i = 0; i <= maxAlp; i++)
    // {
    //     for(int j = 0; j <= maxCop; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    return answer;
}