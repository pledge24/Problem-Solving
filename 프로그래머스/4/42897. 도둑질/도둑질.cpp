#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int moneyN = money.size();
    
    vector<int> dp1(moneyN);    // 첫번째 집 털
    vector<int> dp2(moneyN);    // 첫번째 집 안털
    
    dp1[0] = money[0];
    dp1[1] = max(money[0], money[1]);
    for(int i = 2; i < moneyN-1; i++)
    {
        dp1[i] = max(dp1[i-2] + money[i], dp1[i-1]);
    }
    
    dp2[0] = 0;
    dp2[1] = money[1];
    for(int i = 2; i < moneyN; i++)
    {
        dp2[i] = max(dp2[i-2] + money[i], dp2[i-1]);
    }
    
    answer = max(dp1[moneyN-2], dp2[moneyN-1]);
    
    return answer;
}