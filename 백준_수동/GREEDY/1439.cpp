#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    string S; cin >> S;

    vector<int> num_cnt(2);

    char prev_c = S[0];
    num_cnt[prev_c-'0']++;
    
    for(int i = 1; i < S.length(); i++){
        if(prev_c != S[i]){
            num_cnt[S[i]-'0']++;
            prev_c = S[i];
        }
    }
    
    int ans = min(num_cnt[0], num_cnt[1]);

    cout << ans << '\n';
}