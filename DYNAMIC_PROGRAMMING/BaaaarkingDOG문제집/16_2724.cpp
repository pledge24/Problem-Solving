#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;

    vector<long long> v1(N+1);

    v1[0] = 0, v1[1] = 1; 
    for(int i=2; i<=N; i++){
        v1[i] = v1[i-1] + v1[i-2];
    }
    
    cout << v1[N] << '\n';
}