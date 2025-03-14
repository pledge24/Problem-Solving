#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using int64 = long long;

map<int64, int64> m1;

int64 dp(int64 curN, int64& P, int64& Q){
    if(m1.find(curN) != m1.end())
        return m1[curN];

    m1[curN] = dp(curN/P, P, Q) + dp(curN/Q, P, Q);
        
    return m1[curN];
}

int main(void){
    fastio;
    int64 N, P, Q; cin >> N >> P >> Q;

    m1[0] = 1;
    int64 ans = dp(N, P, Q);

    cout << ans << '\n';

    // for(auto it : m1){
    //     cout << it.first << " " << it.second << '\n';
    // }

    return 0;
}