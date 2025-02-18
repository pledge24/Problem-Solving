#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;
    vector<int> dp(N+1);

    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;

    for(int i = 5; i <= N; i++){
        if(dp[i-1] + dp[i-3] + dp[i-4] < 3){
            dp[i] = 1;
        }
        else dp[i] = 0;
    }

    for(int elem : dp){
        cout << elem;
    }
    cout << '\n';
    
    string ans = dp[N] ? "SK" : "CY";

    cout << ans <<'\n';
}