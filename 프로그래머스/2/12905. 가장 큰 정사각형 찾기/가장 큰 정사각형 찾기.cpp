#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = -1;
    int rows = board.size();
    int cols = board[0].size();
    
    vector<vector<int>> dp(rows, vector<int>(cols));
    
    // Init
    dp[0] = board[0];
    int maxd = 0;
    
    // Process
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(j == 0 || i == 0)
            {
                dp[i][j] = board[i][j];
                maxd = max(maxd, dp[i][j]);
                continue;
            }
            
            if(board[i][j] == 0)
                continue;
            
            dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            maxd = max(maxd, dp[i][j]);
        }
    }
    
    answer = maxd * maxd;
    
    return answer;
}