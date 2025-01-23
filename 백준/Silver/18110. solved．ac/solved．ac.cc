#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int n; cin >> n;

    if(n == 0){
        cout << 0 << '\n';
        return 0;
    }
    
    vector<int> v1(n);
    for(int i = 0; i < n; i++){
        cin >> v1[i];
    }

    sort(v1.begin(), v1.end());

    int cutN = (float)n * 0.15 + 0.5;

    int totalScore = accumulate(v1.begin()+cutN, v1.end()-cutN, 0);
    // cout << totalScore << '\n';
    
    int ans = (float)totalScore / (n - cutN*2) + 0.5;
    cout << ans << '\n';

    return 0;
}