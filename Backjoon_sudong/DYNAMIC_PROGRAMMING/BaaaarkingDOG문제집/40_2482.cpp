#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIV 1000000003

using namespace std;

int main() {
	fastio;
    int N, K; cin >> N >> K;

    vector<vector<long long>> dp(N+1, vector<long long>(K+1));
    
    dp[0][0] = 1, dp[1][0] = 1, dp[1][1] = 1;
    for(int n = 2; n <= N; n++){
        dp[n][0] = 1;
        for(int k = 1; k <= K; k++){
            // k는 N개 이상 뽑을 수 없다.
            if(k >= N){ break;}
            
            dp[n][k] = (dp[n-1][k] + dp[n-2][k-1])%DIV;
        }
    }

    // for(int n = 1; n <= N; n++){
    //     for(int k = 0; k <= K; k++){
    //        cout << dp[n][k] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    long long ans_caseA_type = dp[N-3][K-1];        // 처음을 색 선택으로 시작.
    long long ans_caseB_type = dp[N-1][K];          // 처음을 색 선택 없이 시작.

    int ans = (ans_caseA_type + ans_caseB_type)%DIV;

    cout << ans << '\n';
}