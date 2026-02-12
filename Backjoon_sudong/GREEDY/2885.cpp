#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;

    int K; cin >> K;

    int xk = 1;
    while(xk < K){
        xk *= 2;
    }

    int cnt = 0;
    int left = K;
    int len = xk;
    while(left > 0){
        // 먹을 수 있으면 먹는다.
        if(left - len >= 0){
            left -= len;
            continue;
        }

        // 쪼개 먹어야하는 경우
        len /= 2;
        cnt++;
    }

    int ans = cnt;

    cout << xk << " " << ans << '\n';

    return 0;
}