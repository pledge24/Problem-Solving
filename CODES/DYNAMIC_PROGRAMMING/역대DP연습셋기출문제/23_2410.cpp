#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIV 1000000000

using namespace std;

int main() {
	fastio;
    int N; cin >> N;
    int max_k = log2(N);

    vector<vector<int>> dp;
    dp.resize(N+1, vector<int>(max_k+1, 0));

    fill(dp[0].begin(), dp[0].end(), 1);
    
    for(int n = 1; n <= N; n++){
        for(int k = 0; k <= max_k; k++){
   
            if(k == 0) {
                dp[n][k] = 1; 
                continue;
            }

            dp[n][k] = dp[n][k-1];

            if(n - pow(2, k) >= 0){
                //cout <<  *max_element(dp[n - pow(2, k)].begin(), dp[n - pow(2, k)].end()) << '\n';
                dp[n][k] = (dp[n][k] + *max_element(dp[n - pow(2, k)].begin(), dp[n - pow(2, k)].begin()+k+1)) % DIV; 
            }

        }
    }

    // for(int n = 1; n <= N; n++){
    //     for(int k = 0; k <= max_k; k++){
    //         cout << dp[n][k] << ' ';
    //     }
    //     cout << '\n';
    // }

     cout << dp[N][max_k] << '\n';

    
}