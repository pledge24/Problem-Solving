#include <string>
#include <vector>
#define DIV 1234567
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> dp(n+1);
    
    dp[0] = 0, dp[1] = 1, dp[2] = 1;
    
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % DIV;
    }
    
    answer = dp[n];
    return answer;
}