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

void startTestCase(){
    int M, N, x, y;
    cin >> M >> N >> x >> y;

    int maxN = max(LCM(M, N), 1);

    int ans = -1;
    for(int xx = x; xx <= maxN; xx += M){
        int dd = xx % N == 0 ? N : xx % N;
        if(dd == y){
            ans = xx;
            break;
        }
    }
    cout << ans << '\n';
    return;
}

int main(void){
    fastio;

    int T; cin >> T;
    for(int i = 0; i < T; i++){
        startTestCase();
    }

    return 0;
}

