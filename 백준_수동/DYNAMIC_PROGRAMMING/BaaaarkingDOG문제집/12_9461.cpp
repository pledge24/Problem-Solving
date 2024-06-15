#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int T; cin >> T;

    vector<long long> v1(101);

    v1[1] = 1;
    v1[2] = 1;
    v1[3] = 1;
    v1[4] = 2;
    v1[5] = 2;
    
    for(int i = 6; i <= 100; i++){
        v1[i] = v1[i-1] + v1[i-5] ;
        //printf("i = %d, v1[i] = %lld\n", i, v1[i]);
    }

    int n;
    for(int i = 0; i < T; i++){
        cin >> n;
        cout << v1[n] << '\n';
    }
    
}