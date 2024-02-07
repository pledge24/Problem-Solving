#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;

    vector<int> Ti(N+1);
    vector<int> Pi(N+1);

    for(int i = 1; i <= N; i++){
        cin >> Ti[i] >> Pi[i];
    }

    vector<int> dp(N+2);
    for(int n = 1; n <= N; n++){
        dp[n] = max(dp[n-1], dp[n]);

        int next_n = n + Ti[n];
        if(next_n > N + 1) continue;

        dp[next_n] = max(dp[next_n], dp[n] + Pi[n]);

        
        // cout << "n is " << n << ": ";
        // for(int elem : dp){
        //     cout << elem << ' ';
        // }
        // cout << '\n';
    }

    // for(int elem : dp){
    //         cout << elem << ' ';
    //     }
    //     cout << '\n';

    cout << max(dp[N], dp[N+1]) << '\n';

}