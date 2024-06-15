#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;

    vector<int> v1(N+1);
    v1[0] = 1, v1[2] = 3, v1[4] = 11;
    for(int i = 6; i <= N; i++){
        if(i % 2 == 1){
            v1[i] = 0;
        }
        else{
            v1[i] = v1[i-2]*3;
            for(int j = i-4; j >= 0; j-=2){
                v1[i] += v1[j]*2;
            }
        }

        //cout << v1[i] << ' ';
    }
    //cout << '\n';

    int ans = v1[N];

    cout << ans << '\n';
    
}