#include <string>
#include <vector>

#define DIV 1234567

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<long long> dp(n+1);
    dp[1] = 1, dp[2] = 2;
    
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2])%DIV;
    }
     
    answer = dp[n];
    return answer;
}