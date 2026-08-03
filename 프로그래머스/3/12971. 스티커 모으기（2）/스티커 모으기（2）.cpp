#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;

    int N = sticker.size();
    vector<int> dp1(N);   // 첫번째 안 뗌
    vector<int> dp2(N);   // 첫번째 뗌
    
    // Init
    dp1[0] = 0;
    dp1[1] = std::max(0, sticker[1]);
    dp2[0] = sticker[0];
    dp2[1] = std::max(sticker[0], sticker[1]);
    
    // Process
    for(int i = 2; i < N; i++)
    {
        dp1[i] = std::max(dp1[i-2] + sticker[i], dp1[i-1]);
        dp2[i] = i < N-1 ? std::max(dp2[i-2] + sticker[i], dp2[i-1]) : dp2[i-1];
    }
    
    answer = std::max(dp1.back(), dp2.back());
    
    return answer;
}