#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v1;

int dp(int x){   
    if(v1[x] != 0) return v1[x];

    v1[x] = ((2*dp(x-2) + dp(x-1)) % 10007);

    return v1[x];

}
int main(void){
    cin >> N;
    v1.resize(N+1);
    
    v1[1] = 1, v1[2] = 3;
    
    cout << dp(N) << '\n';

    // v1[1] = 1, v1[2] = 2;

    // for(int i = 3; i <= N; i++){
    //     v1[i] = v1[i-1] + v1[i-2];
    // }

    // cout << v1[N] % 10007 << '\n';

    return 0;
}