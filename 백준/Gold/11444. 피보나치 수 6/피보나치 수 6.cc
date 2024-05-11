#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define MOD 1'000'000'007

using namespace std;

map<long long, long long> m;

long long fibonacci(long long N){

    if(N <= 2) return 1;

    //long long cur_num = -1;

    if(N % 2){
        long long f1 = m[N/2] == 0 ? fibonacci(N/2) : m[N/2];
        long long f2 = m[N/2+1] == 0 ? fibonacci(N/2+1) : m[N/2+1];
        
        m[N/2] = f1, m[N/2+1] = f2;

        return (f1*f1 + f2*f2) % MOD;
    }
    else{
        long long f1 = m[N/2] == 0 ? fibonacci(N/2) : m[N/2];
        long long f2 = m[N/2-1] == 0 ? fibonacci(N/2-1) : m[N/2-1];

        m[N/2] = f1, m[N/2-1] = f2;

        return (f1*f1 + f1*f2*2) % MOD;
    }
}

int main() {
	fastio;
    long long N; cin >> N;

    int ans = fibonacci(N);

    cout << ans << '\n';
    
}