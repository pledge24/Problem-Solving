#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N, K; cin >> N >> K;
    vector<vector<int>> dp;
    dp.resize(N+1, vector<int>(K+1, 0));

    int W, V;
    for(int i = 1; i <= N; i++){
        cin >> W >> V;
        for(int j = 1; j <= K; j++){
            if(j < W){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-W] + V);
            }
            
        }
    }
    

    // for(int i = 1; i <= N; i++){
    //     for(int j = 1; j <= K; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int ans = dp[N][K];

    cout << ans << '\n';
}