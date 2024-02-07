#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIV 1000000000

using namespace std;

int main() {
	fastio;
    int N, K; cin >> N >> K;
    vector<vector<long long>>dp(K+1, vector<long long>(N+1));

    dp[0][0] = 1;
    for(int k = 1; k <= K; k++){
        for(int n = 0; n <= N; n++){
            if(n == 0) {
                dp[k][n] = 1;
                continue;
            }

            dp[k][n] = (dp[k-1][n] + dp[k][n-1])%DIV;
        }
    }
  
    // // print test
    // for(int i = 0; i <= K; i++){
    //     for(int j = 0; j <= N; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    int ans = dp[K][N];

    cout << ans << '\n';
}