#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
long long cnt = 0;
long long solve(int num, int exp, int mod){
    cnt++;
    long long cur_ans = -1;

    if(exp == 1) return num % mod;
    
    if(exp % 2){
        cur_ans = solve(num, (exp-1)/2, mod);
        return (cur_ans * cur_ans * num) % mod;
    }
    else{
        cur_ans = solve(num, exp/2, mod);
        return (cur_ans * cur_ans) % mod;
    }
    

    return 1;
}


int main() {
	fastio;
    int A, B, C; cin >> A >> B >> C;
    
    int ans = solve(A, B, C);

    cout << ans << '\n';
    cout << cnt << '\n';
}