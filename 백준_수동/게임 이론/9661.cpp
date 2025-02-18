#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    long long N; cin >> N;

    vector<long long> dp(N+1, 1);
    dp[0] = 0;  
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    dp[4] = 1;
    for(long long i = 5; i <= N; i++){
        long long x = 1;
        while(i-x > 0){
            dp[i] *= dp[i-x];
            x *= 4;
        }       
        dp[i] != dp[i];

    }

    for(int elem : dp){
        cout << elem;
    }
    cout << '\n';

    return 0;
}