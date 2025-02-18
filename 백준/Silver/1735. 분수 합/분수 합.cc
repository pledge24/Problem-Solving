#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

// 시간복잡도 O(logN)
int gcd(int a, int b) {
    while (b != 0) {
        int r = b;
        b = a % b;
        a = r;
    }
    return a;
}

int main(void){
    fastio;
    int a1, b1; cin >> a1 >> b1;
    int a2, b2; cin >> a2 >> b2;

    int up = a1*b2 + a2*b1;
    int down = b1*b2;

    int gcdNum = gcd(up, down);

    cout << up/gcdNum << " " << down/gcdNum << '\n';
    
    return 0;
}