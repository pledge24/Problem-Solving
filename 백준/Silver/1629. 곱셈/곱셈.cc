#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

long long solve(int num, int exp, int mod){
    if(exp == 0) return 1;
    if(exp == 1) return num % mod;
    
    if(exp % 2){
        long long temp = solve(num, (exp-1)/2, mod);
        return ((temp * temp % mod) * num) % mod;
    }
    else{
        long long temp = solve(num, exp/2, mod);
        return (temp * temp) % mod;
    }
}

int main() {
	fastio;
    int A, B, C; cin >> A >> B >> C;
    
    long long ans = solve(A, B, C);

    cout << ans << '\n';
}
