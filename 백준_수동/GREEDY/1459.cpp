#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    long long x, y, w, s; cin >> x >> y >> w >> s;

    bool useCross = s < 2*w;

    long long ans = 0;

    if(useCross){
        long long div = abs(x-y);
        long long quient = abs(x-y) % 2;
        if(s < w){
            ans = min(x, y)*s + (div-quient)*s + quient*w;
        }
        else{
            ans = min(x, y)*s + abs(x-y)*w;
        }
        
    }
    else{
        ans = (x + y) * w;
    }

    cout << ans << '\n';

    return 0;
}