#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;

    vector<int> dp(N+1, 1);
    dp[0] = 0;
    for(int i = 1; i <= N; i++){
        int minCnt = INT32_MAX;
        for(int j = sqrt(i); j >= 1; j--){
            int square = j*j;
            minCnt = min(minCnt, (dp[square] + dp[i-square]));
        }
        dp[i] = minCnt;
    }

    cout << dp[N] << '\n';

    // for(int elem : dp){
    //     cout << elem << ' ';
    // }
    // cout << '\n';

    return 0;
}