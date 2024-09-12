#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    string S; cin >> S;

    vector<int> num_cnt(2);

    char prev_idx = 0;
    for(int i = 1; i < S.length(); i++){
        if(S[prev_idx] != S[i]){
            num_cnt[S[prev_idx]-'0']++;
            prev_idx = i;
        }
    }
    
    if(prev_idx < S.length()-1 && S[prev_idx] == S[S.length()-1]){
        num_cnt[S[prev_idx]-'0']++;
    }
    int ans = min(num_cnt[0], num_cnt[1]);

    cout << ans << '\n';
}