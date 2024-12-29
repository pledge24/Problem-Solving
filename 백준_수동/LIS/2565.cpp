#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;
    vector<pair<int, int>> v1(N+1);

    for(int i=1; i<=N; i++){
        int a, b;
        cin >> a >> b;
        v1[i] = make_pair(a, b);       
    }
    
    sort(v1.begin(), v1.end());

    vector<int> L(N+1);
    int len = 0;
    for(int i = 1; i <= N; i++){
        auto pos = lower_bound(L.begin()+1, L.begin()+1+len, v1[i].second);
        *pos = v1[i].second;
        if(pos == L.begin()+1+len)
            len++;
    }
    
    int ans = len;

    cout << N - ans << '\n';        
}