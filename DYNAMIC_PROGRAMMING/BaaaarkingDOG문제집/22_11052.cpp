#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N;
vector<int> dp;
vector<int> Pi;

int found_max(int idx){
    int sub_max = Pi[idx];

    for(int i=1; i<idx; i++){
        sub_max = max(sub_max, dp[i] + Pi[idx-i]);
    }
 
    //cout << sub_max << ' ';
    return sub_max;
}

int main() {
	fastio;
    cin >> N;

    dp.resize(N+1);
    Pi.resize(N+1);
    
    for(int i = 1; i <=N; i++){
        cin >> Pi[i];
    }
    
    dp[1] = Pi[1];

    for(int i = 2; i <= N; i++){
        dp[i] = found_max(i);
    }
    //cout << '\n';
    int ans = dp[N];

    cout << ans << '\n';
}
    