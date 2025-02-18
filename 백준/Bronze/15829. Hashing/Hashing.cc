#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;

    long long R = 31;
    long long M = 1234567891;
    int L; cin >> L;

    long long ans = 0;
    for(int i = 0; i < L; i++){
        char c; cin >> c;
        long long num = (c - 'a') + 1;

        for(int j = 0; j < i; j++){
            num = (num * R) % M;
        }

        ans = (ans + num) % M;
    }

    cout << ans << '\n';

    return 0;
}