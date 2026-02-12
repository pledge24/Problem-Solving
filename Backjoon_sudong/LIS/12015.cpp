#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void solve(int t){

}

int main() {
	fastio;

    int N, K; cin >> N >> K;

    vector<int> v1(N+1), L(N+1), LN(N+1);
    int len = 0;
    int num;
    for(int i = 1; i <= N; i++){
        cin >> num;
        v1[i] = num; 
        auto pos = lower_bound(L.begin()+1, L.begin()+1+len, v1[i]);
        *pos = v1[i];
        if(pos == L.begin()+1+len)
            len++;
    }
    
    
}
