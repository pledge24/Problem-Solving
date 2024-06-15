#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIV 1'000'000'000
#define MAXN 1'000'000

using namespace std;

int main() {
	fastio;
    int N; cin >> N;
    int max_k = log2(N);

    vector<vector<int>> dp;
    vector<int> last_pos;
    dp.resize(MAXN+1, vector<int>(max_k+1));        // N -> MAXN으로 변경했는데 통과한 이유...?
    last_pos.resize(MAXN+1);

    dp[1][0] = 1;
    dp[2][0] = 1, dp[2][1] = 2;

    last_pos[1] = 0;
    last_pos[2] = 1;

    // pow(2, k) -> (1 << k)로 바꾸기만 했는데도 시간초과 문제가 해결됨.
    for(int n = 3; n <= N; n++){
        for(int k = 0; n >= (1 << k); k++){
   
            if(k == 0) {
                dp[n][k] = 1; 
                continue;
            }

            if(n - (1 << k) > 0){
                int x = min(last_pos[n-(1 << k)], k);
                dp[n][k] = (dp[n][k-1] + dp[n-(1 << k)][x]) % DIV; 
            }
            else if((n - (1 << k)) == 0){
                dp[n][k] = (dp[n][k-1] + 1) % DIV;
            }

            last_pos[n] = k;
        }
        
    }

    cout << dp[N][max_k] << '\n';

}