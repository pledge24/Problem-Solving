#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIV 10007

using namespace std;

long long nCm(int n, int m){
    
    vector<vector<long long>> dp(n+1, vector<long long>(n+1));

    dp[1] = {1, 1};
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0){
                dp[i][j] = 1;
                continue;
            } 

            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % DIV;
        }
    }

    return dp[n][m];
}

int main() {
	fastio;
    
    int N, K; cin >> N >> K;

    long long ans = nCm(N, K);

    cout << ans << '\n';
    
}