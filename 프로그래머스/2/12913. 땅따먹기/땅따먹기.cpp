#include <bits/stdc++.h>

using namespace std;

// 1행부터 아래로 이동하는데, 각 행의 4칸중 하나만 밟아서 내려가야함.
// 단, 같은 열을 연속해서 밟을 수 없음.

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int rows = land.size();
    int cols = 4;
    
    vector<vector<int>> dp(rows, vector<int>(cols));
    dp[0] = land[0];
    for(int r = 1; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            int maxScore = 0;
            for(int prevC = 0; prevC < cols; prevC++)
            {
                if(prevC == c)
                    continue;
                
                maxScore = max(maxScore, dp[r-1][prevC] + land[r][c]);
            }
            
            dp[r][c] = maxScore;
        }
    }
    
    vector<int>& lastRow = dp[rows-1];
    answer = *max_element(lastRow.begin(), lastRow.end());

    return answer;
}