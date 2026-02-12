#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;
    
    vector<int> v1(N+1);
    int maxStreak = -1;
    for(int i = 0; i < N; i++){
        int num; cin >> num;
        v1[num] = v1[num-1]+1;
        maxStreak = max(maxStreak, v1[num]);
    }
    
    int ans = N - maxStreak;

    cout << ans << '\n'; 
}