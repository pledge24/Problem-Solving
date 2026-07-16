#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int N = triangle.size();
    
    // Init.
    vector<vector<int>> dp(N);
    for(int i = 0; i < N; i++)
    {
        dp[i].resize(i+1);    
    }
    
    // Process.
    dp[0][0] = triangle[0][0];
    for(int i = 1; i < N; i++)
    {
        vector<int>& prev = dp[i-1];
        for(int j = 0; j < triangle[i].size(); j++)
        {
            int left = j > 0 ? prev[j-1] : 0;
            int right = j < prev.size() ? prev[j] : 0;
            
            dp[i][j] = std::max(left, right) + triangle[i][j];
        }
    }
    
    // Debug
    // for(int i = 0; i < dp.size(); i++)
    // {
    //     for(int j = 0; j < dp[i].size(); j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    vector<int>& last = dp.back();
    answer = *max_element(last.begin(), last.end());
    
    return answer;
}