#include <bits/stdc++.h>

#define MAX 1000001
#define MOD 1000000009

using namespace std;

vector<long long> v1(MAX);


int main(){

    v1[1] = 1, v1[2] = 2, v1[3] = 4;

    int T, n;
    cin >> T;

    for(int i = 4; i < MAX; i++){
        v1[i] = (v1[i-1] + v1[i-2] + v1[i-3]) % MOD;
    }

    for(int i = 0; i < T; i++){  
        cin >> n;           
        cout << v1[n] << '\n';
    }

    return 0;
}