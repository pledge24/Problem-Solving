#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;
    
    vector<int> v1(N+1);
    for(int i = 1; i <=N; i++){
        cin >> v1[i];
    }

    vector<int> dp(N+1);
    dp[1] = 1;
    for(int i = 2; i <=N; i++){

        for(int j = 1; j < i; j++){
            if(v1[j] < v1[i]){
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i]++;
    }

    // for(int i = 1; i <=N; i++){
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';

    int ans = *max_element(dp.begin(), dp.end());

    cout << ans << '\n';
}