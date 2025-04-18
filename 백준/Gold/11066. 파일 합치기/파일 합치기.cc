#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using int64 = long long;
using DP = vector<vector<int64>>;

int64 memoization(vector<int64>& accuV1, DP& dp, int s, int e){
    // 이미 구함.
    if(dp[s][e] != -1){
        return dp[s][e];
    }

    int64 minCost = INT64_MAX;
    for(int i = s; i < e; i++){
        int64 accuCost = memoization(accuV1, dp, s, i) + memoization(accuV1, dp, i+1, e);
        int64 mergeCost = (accuV1[i] - accuV1[s-1])/*s <= x <= i*/ + (accuV1[e] - accuV1[i])/*i+1 <= x <= e*/;

        // printf("s = %d, i = %d, e = %d\n", s, i, e);
        // printf("s~i size = %lld, (i+1)~e size = %lld, accuCost = %lld, mergeCost = %lld\n", (accuV1[i] - accuV1[s-1]), (accuV1[e] - accuV1[i]), accuCost, mergeCost);
        minCost = min(minCost, accuCost + mergeCost);
    }
    dp[s][e] = minCost;

    // printf("s = %lld, e = %lld, dp[s][e] = %lld\n", s, e, dp[s][e]);
    return dp[s][e];
}

void startTest(){
    int N; cin >> N;

    // input data.
    vector<int64> v1(N+1);
    vector<int64> accuV1(N+1);
    for(int i = 1; i <= N; i++){
        cin >> v1[i];
        accuV1[i] = accuV1[i-1] + v1[i];
    }

    // r장 부터 c장까지 합쳤을 때 최소값
    vector<vector<int64>> dp(N+1, vector<int64>(N+1, -1));

    // DP init.
    for(int i = 1; i <= N; i++){
        dp[i][i] = 0;
    }

    // calc DP.
    int64 ans = memoization(accuV1, dp, 1, N);

    cout << ans << '\n';
}

int main(void){
    fastio;
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        startTest();
    }

    return 0;
}