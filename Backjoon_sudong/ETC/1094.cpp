#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;

    int cnt = 0;
    while(N > 0){
        cnt += N % 2;
        N /= 2;
    }

    cout << cnt << '\n';

    return 0;
}