#include <string>
#include <vector>

#define DIV 10'007

using namespace std;

int solution(int n, vector<int> tops) {
    int answer = 0;
    
    vector<pair<int, int>> dp(n+1); // 오른쪽 마름모 사용 X, O
    dp[0] = tops[0] == 1 ? make_pair(3, 1) : make_pair(2, 1);
    // i 번째 삼각형까지의 최대 경우의 수
    for(int i = 1; i < n; i++){
        if(tops[i] == 1/*삼각형*/){
            dp[i].first = (dp[i-1].first*3 + dp[i-1].second*2) % DIV;
            dp[i].second = (dp[i-1].first + dp[i-1].second) % DIV;
        }
        else/*사다리꼴*/{
            dp[i].first = (dp[i-1].first*2 + dp[i-1].second) % DIV;
            dp[i].second = (dp[i-1].first + dp[i-1].second) % DIV;
        }
    }
    
    answer = (dp[n-1].first + dp[n-1].second) % DIV;
    
    return answer;
}