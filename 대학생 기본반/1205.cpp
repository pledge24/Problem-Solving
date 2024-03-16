#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N, P; long long TS_score; cin >> N >> TS_score >> P;

    vector<long long> v1(P+1, -1);
    for(int i = 1; i <= N; i++){
        cin >> v1[i];
    }
    
    // 랭킹에 아무도 없으면 무조건 1등.
    if(N == 0){
        int ans = 1;
        cout << ans << '\n';
        return 0;
    }
    
    // // print test
    // for(int elem : v1){
    //     cout << elem << ' ';
    // }
    // cout << '\n';

    int ans = -1;
 
    for(int i = 1; i <= P; i++){
        
        if(TS_score >= v1[i]){
            ans = i;
            break;
        }
    }

    if(TS_score == v1[P]) ans = -1;
    
    cout << ans << '\n';
}