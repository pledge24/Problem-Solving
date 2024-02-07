#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIGITS 10

using namespace std;

int main() {
	fastio;
    int N; cin >> N;

    vector<int> v1(DIGITS+1, 1);
    vector<int> v2(DIGITS+1);


    for(int i=1; i<N; i++){
        for(int j=1; j<=DIGITS; j++){
            v2[j] = accumulate(v1.begin()+1, v1.begin()+j+1, 0) % 10007;
        }
        v1 = v2;
    }
    
    // for(int i=1; i<=DIGITS; i++){
    //     cout << v1[i] << ' ';
    // }
    // cout << '\n';
    
    int ans = accumulate(v1.begin()+1, v1.end(), 0) % 10007;
    cout << ans << '\n';
}