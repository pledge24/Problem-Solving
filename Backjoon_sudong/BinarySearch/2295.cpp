#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using int64 = long long;

set<int64> s1;

bool func1(vector<int64>& v1, int64 idx){
    for(int64 j = idx-1; j >= 0; j--){
        int64 gap = v1[idx] - v1[j];
        if(s1.find(gap) != s1.end()){
            return true;
        }
    }

    return false;
}

int main(void){
    fastio;
    int64 N; cin >> N;

    vector<int64> v1(N);
    for(int64 i = 0; i < N; i++){
        cin >> v1[i];
    }

    for(int64 i = 0; i < N; i++){
        for(int64 j = 0; j < N; j++){
            int64 sum = v1[i] + v1[j];
            s1.insert(sum);
        }
    }

    sort(v1.begin(), v1.end());

    int64 ans = 0;
    for(int64 i = N-1; i >= 0; i--){
        if(func1(v1, i)){
            ans = v1[i];
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}