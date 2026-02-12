#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;
    map<long long, int> m;
    for(int i = 0; i < N; i++){
        long long num; cin >> num;
        m[num]++;
    }

    pair<long long, int> ans; // num, cnt
    for(auto elem : m){
        if(ans.second < elem.second){
            ans = elem;
            continue;
        }

        if(ans.second == elem.second && ans.first > elem.first){
            ans = elem; 
        }
    }

    cout << ans.first << '\n';

    return 0;
}