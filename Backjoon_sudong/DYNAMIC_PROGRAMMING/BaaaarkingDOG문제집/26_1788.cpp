#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIV 1000000000
using namespace std;

int main() {
	fastio;

    int n; cin>> n;

    vector<int> v1(abs(n)+1);
    if(n >= 0){
        v1[0] = 0, v1[1] = 1;
        for(int i = 2; i<=n; i++){
            v1[i] = (v1[i-1] + v1[i-2]) % DIV;
        }
    }
    else{
        v1[1] = 1, v1[2] = -1;
        for(int i = 3; i<=-n; i++){
            v1[i] = (v1[i-2] - v1[i-1]) % DIV;
        }
    }
    
    n = abs(n);

    int sign = (v1[n] > 0) ? 1 : ((v1[n] < 0) ? -1 : 0);
    int ans = abs(v1[n]);

    cout << sign << '\n';
    cout << ans << '\n';

}