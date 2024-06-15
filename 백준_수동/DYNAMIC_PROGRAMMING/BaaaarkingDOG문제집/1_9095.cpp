#include <bits/stdc++.h>

using namespace std;

vector<int> v1(12);

int solve(int n){

    if(v1[n] != 0) return v1[n];

    v1[n] = solve(n-1) + solve(n-2) + solve(n-3);

    return v1[n];   
}

int main(){

    v1[1] = 1, v1[2] = 2, v1[3] = 4;

    int T, n;
    cin >> T;

    for(int i = 0; i < T; i++){  
        cin >> n;           
        cout << solve(n) << '\n';
    }

    return 0;
}