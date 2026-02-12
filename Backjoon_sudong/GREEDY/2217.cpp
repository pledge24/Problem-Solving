#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int k; cin >> k;

    vector<int> v1;
    v1.resize(k);
    for(int i = 0; i < k; i++){
        cin >> v1[i];
    }
    
    sort(v1.begin(), v1.end(), greater<int>());

    int ans = 0;
    for(int i = 0; i < k; i++){
       ans = max(ans, (i+1)*v1[i]);
    }
    cout << ans << '\n';
}