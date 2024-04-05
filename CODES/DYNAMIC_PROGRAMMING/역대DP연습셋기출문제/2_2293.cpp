#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<int> sum(100001);

int dp(int K){
    if(K < 1) return 0;
    if(sum[K] != 0) return sum[K];

    return sum[K] + dp(K-1) + dp(K-2) + dp(K-5);
}

int main() {
	fastio;
    int N, K; cin >> N >> K;

    int num;
    for(int i = 0; i < N; i++){
        cin >> num;
        sum[num] = 1;
    }
    
    for(int i = 1; i<=K; i++){
        sum[i] = dp(i);
    }

    for(int i = 1; i<=K; i++){
        cout << sum[i] << ' ';
    }
    cout << '\n';
    cout << dp(K) << '\n';
}