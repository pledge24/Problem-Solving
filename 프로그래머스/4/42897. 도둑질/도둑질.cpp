#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int moneyN = money.size();
    
    if(moneyN == 3)
        return max(money[0] + money[2], money[1]);
    
    // ===n이 4 이상인 경우===
    
    // 첫번째 집 털
    {
        vector<int> dp1(moneyN);
        vector<int> dp2(moneyN);
        dp1[2] = money[0] + money[2];
        dp2[2] = money[0];
        for(int i = 3; i < moneyN; i++)
        {
            if(i == moneyN-1)
            {
                dp1[i] = dp1[i-1];
                dp2[i] = dp2[i-1];
                continue;
            }
            
            dp1[i] = dp2[i-1] + money[i];
            dp2[i] = max(dp1[i-1], dp2[i-1]);
        }
        
        answer = max(dp1[moneyN-1], dp2[moneyN-1]);
    }
    
    
    // 첫번째 집 안털
    {
        vector<int> dp1(moneyN);
        vector<int> dp2(moneyN);
        dp1[1] = money[1];
        dp2[1] = 0;
        for(int i = 2; i < moneyN; i++)
        {
            dp1[i] = dp2[i-1] + money[i];
            dp2[i] = max(dp1[i-1], dp2[i-1]);
        }
        
        answer = max({answer, dp1[moneyN-1], dp2[moneyN-1]});
    }
    
    return answer;
}