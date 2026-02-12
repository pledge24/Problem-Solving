#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ALPAH 30

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;
    string str; cin >> str;

    vector<int> src(ALPAH);
    for(char c : str){
        src[c-'A']++;
    }

    int ans = 0;
    for(int i = 0; i < N-1; i++){
        string temp; cin >> temp;

        vector<int> tgt(ALPAH);
        for(char c : temp){
            tgt[c-'A']++;
        }

        int overN = 0;
        int underN = 0;
        for(int i = 0; i < ALPAH; i++){
            int diff = tgt[i] - src[i];
            if(diff > 0) overN += diff;
            else underN += abs(diff);
        }

        int gap = overN + underN;
        if(gap < 2)
            ans++;
        else if(overN == 1 && underN == 1)
            ans++;
        
        // cout << "diff: " << diff << '\n';
    }

    cout << ans << '\n';

    return 0;
}