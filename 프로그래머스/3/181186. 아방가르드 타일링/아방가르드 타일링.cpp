#include <bits/stdc++.h>

#define DIV 1'000'000'007
#define MAXN 100'000

using namespace std;
using int64 = long long;

int solution(int n) {
    int answer = 0;
    
    vector<int64> dp(MAXN+1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 10;
    
    vector<int64> dpAccu(MAXN+1);
    for(int i = 4; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2]*2 + dp[i-3]*5) % DIV;

        // 확장 구조: 계단식 가로 막대 3개 패턴을 확장해 고유한 패턴을 반복적으로 생성되는 구조
        // w = 4 시작 -> 2가지
        // w = 5 시작 -> 2가지
        // w = 6 시작 -> 4가지
        for(int backN = 4; backN <= 6 && backN <= i; backN++){
            int64 multiplyN = backN < 6 ? 2 : 4;
            
            dpAccu[i] += dp[i - backN] * multiplyN;
            dpAccu[i] %= DIV;
        }
        
        dpAccu[i] += dpAccu[i-3]; // 이전 주기 값을 더한다.
        dpAccu[i] %= DIV;
        
        // 누적값을 더한다.
        dp[i] += dpAccu[i];
        dp[i] %= DIV;
    }
    
    answer = dp[n] % DIV;
    
    return answer;
}