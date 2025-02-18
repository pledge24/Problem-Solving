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

// 시간복잡도 O(N)
int LCM(int a, int b){
    return a * b / gcd(a, b);
}

int main() {
	fastio;

    int A, B; cin >> A >> B;

    cout << gcd(A, B) << '\n';
    cout << LCM(A, B) << '\n';
}