#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;

    vector<int> v1(N);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    int ans = 0;

    for(int i = N-2; i >= 0; i--){
        if(v1[i] >= v1[i+1]){
            ans += v1[i] - v1[i+1] + 1;
            v1[i] = v1[i+1] - 1;
        }      
    }

    cout << ans << '\n';
}