#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;

    int sizeN = 6;
    vector<int> v1(sizeN);
    for(int i = 0; i < sizeN; i++){
        cin >> v1[i];
    }

    int T, P; cin >> T >> P;

    int numOfT = 0;
    for(int i = 0; i < sizeN; i++){
        int p = v1[i] / T;
        int q = (v1[i] % T) > 0;

        numOfT += p+q;
    }

    cout << numOfT << '\n';

    int p = N / P;
    int q = N % P;

    cout << p << " " << q << '\n';

    return 0;
}