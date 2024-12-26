#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

long long nCm(int n, int m){
    
    vector<vector<long long>> dp(31, vector<long long>(31));

    dp[1] = {1, 1};
    dp[2] = {1, 2, 1};
    for(int i = 3; i <= 30; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0){
                dp[i][j] = 1;
                continue;
            } 

            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    return dp[n][m];
}

int main() {
	fastio;
    
    int T; cin >> T;

    for(int i = 0; i < T; i++){
        int N, M; cin >> N >> M;
        long long ans = nCm(M, N);

        cout << ans << '\n';
    }
    
}