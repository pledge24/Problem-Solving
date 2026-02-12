#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIV 1'000'000'007

using namespace std;

map<pair<int, int>, long long> m1;

long long nCm(int n, int k){
    
    // n은 1이상, k는 0이상
    if(n < 1 || k < 0) return 0;
    else if(k == 0) return 1;

    if(m1[{n, k}] == 0){
        m1[{n, k}] = (nCm(n-1, k-1) + nCm(n-1, k)) % DIV;
    }
    
    return m1[{n, k}];
}

int main() {
	fastio;
    
    int N, K; cin >> N >> K;

    m1[{1, 0}] = 1;
    m1[{1, 1}] = 1;

    long long ans = nCm(N, K);

    cout << ans << '\n';

    // for(int i = 1; i <= 5; i++){
    //     for(int j = 0; j <= 5; j++){
    //         cout << m1[{i, j}] << ' ';
    //     }
    //     cout << '\n';
    // }
    
}