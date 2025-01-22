#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;

    enum {R = 31, M = 1234567891};

    int L; cin >> L;

    int ans = 0;
    for(int i = 0; i < L; i++){
        char c; cin >> c;
        int num = (c - 'a') + 1;

        for(int j = 0; j < i; j++){
            num = (num * R) % M;
        }

        ans += num;
    }

    cout << ans << '\n';
    
    return 0;
}