#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;

    vector<int> dp(N+1);
    for(int i = 1; i <= N; i++){

        int minCnt = INT32_MAX;
        for(int j = sqrt(i); j >= 1; j--){
            int square = j*j;

            // i가 제곱수인 경우
            if(square == i){
                minCnt = 1;
                break;
            }

            // i가 제곱수가 아닌 경우
            minCnt = min(minCnt, (dp[square] + dp[i-square]));
        }
        dp[i] = minCnt;
    }

    cout << dp[N] << '\n';

    return 0;
}