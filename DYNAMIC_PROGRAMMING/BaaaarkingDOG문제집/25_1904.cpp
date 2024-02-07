#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIV 15746
using namespace std;

int main() {
	fastio;
    int N; cin >> N;

    vector<int> v1(N+1);
    vector<int> v2(N+1);

    v1[1] = 1, v1[2] = 1;
    v2[1] = 0, v2[2] = 1;

    for(int i = 3; i <= N; i++){
        v1[i] = (v1[i-1] + v2[i-1]) % DIV;
        v2[i] = v1[i-2] + v2[i-2] % DIV;
    }
    
    int ans = (v1[N] + v2[N]) % DIV;;

    cout << ans << '\n';
}