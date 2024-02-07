#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX_POW 100000

using namespace std;

int main() {
	fastio;
    int N; cin >> N;

    vector<int> v1(N+1, MAX_POW+1);
    int square_n = 1;
    v1[1] = 1;
    for(int i = 2; i<=N; i++){
        if((square_n + 1) * (square_n + 1) == i){
            v1[i] = 1;
            square_n++;
            continue;
        }

        for(int square_temp = 1; square_temp <= square_n; square_temp++){
            v1[i] = min(v1[i], v1[i-(square_temp*square_temp)] + 1);
        }
    }
    
    // print test
    // for(int i = 1; i <= N; i++){
    //     cout << v1[i] << ' ';
    // }
    // cout << '\n';

    int ans = v1[N];

    cout << ans << '\n';
}