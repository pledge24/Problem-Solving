#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int memoization(vector<int>& dp, int leftN, int maxNum){
    if(dp[leftN] > 0)
        return dp[leftN];
    
    int res = 0;
    for(int i = maxNum; i >= 1; i--){
        if(leftN - i > 0)
            res += memoization(dp, leftN-i, i);
    }

    dp[leftN] = res;

    return dp[leftN];
}

void startTest(){
    int n; cin >> n;

    vector<int> dp(n+1);
    dp[1] = 1; dp[2] = 2; dp[3] = 3;
    for(int i = 4; i <= n; i++){
        dp[i] += dp[i-3];
        dp[i] += (i-2)/2 + 1;
        dp[i] += 1;
    }
    // int ans = memoization(dp, n, 3);

    // for(int elem : dp)
    //     cout << elem << ' ';
    // cout << '\n';
    cout << dp[n] << '\n';
}

int main(void){
    fastio;

    int T; cin >> T;
    for(int i = 0; i < T; i++){
        startTest();
    }

    return 0;
}