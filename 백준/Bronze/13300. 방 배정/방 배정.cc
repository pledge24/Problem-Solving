#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N, K; cin >> N >> K;
    vector<pair<int, int>> v1(7);
    for(int i = 0; i < N; i++){
        int gender, grade; cin >> gender >> grade;

        if(gender == 0/*female*/)
            v1[grade].second++;
        else
            v1[grade].first++;
    }

    int cnt = 0;
    for(int i = 1; i <= 6; i++){
        cnt += (v1[i].first / K) + (v1[i].first % K > 0);
        cnt += (v1[i].second / K) + (v1[i].second % K > 0);
    }

    cout << cnt << '\n';
    
    return 0;
}