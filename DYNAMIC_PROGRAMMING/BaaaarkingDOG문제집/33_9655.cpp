#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;

    vector<int> v1(N+1);
    v1[1] = 1, v1[2] = 2, v1[3] = 1;
    for(int i = 4; i <= N; i++){
        v1[i] = min(v1[i-1], v1[i-3]) + 1;
    }
    
    string ans = v1[N] % 2 == 1 ? "SK" : "CY";

    cout << ans <<'\n';
}