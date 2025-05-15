#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using int64 = long long;

int main(void){
    fastio;
    int64 A, B; cin >> A >> B;
    
    int64 tempA = A;
    int64 tempB = B - (B % 4);

    int64 res = 0;
    while(tempA % 4 > 0){
        // cout << "tempA: " << tempA << '\n';
        res ^= tempA;
        tempA++;
    }

    while(tempB <= B){
        // cout << "tempB: " << tempB << '\n';
        res ^= tempB;
        tempB++;
    }

    cout << res << '\n';

    return 0;
}