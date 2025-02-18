#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void dfs(int idx, int num, vector<int>& P, vector<int>& v1){
    if(idx == 0) return;

    if(P[idx] == num){
        dfs(idx - 1, num - 1, P, v1);
        v1[idx] = 0;
    }
    else{
        dfs(idx - 1, num, P, v1);
    }
}

int main() {
	fastio;
    int N; cin >> N;

    vector<int> v0(N+1), v1(N+1), L(N+1), P(N+1);
    vector<pair<int, int>> p1(N+1);
    map<int, int> m1, m2;
    for(int i = 1; i <= N; i++){
        cin >> p1[i].first;
        m1[p1[i].first] = i;
        m2[i] = p1[i].first;
    }

    for(int i = 1; i <= N; i++){
        cin >> p1[i].second;
    }

    for(int i = 1; i <= N; i++){     
        v0[i] = m1[p1[i].first];
        v1[i] = m1[p1[i].second];
    }

    int len = 0;
    for(int i = 1; i <= N; i++){
        auto idx = lower_bound(L.begin()+1, L.begin()+len+1, v1[i]);
        *idx = v1[i];
        P[i] = distance(L.begin(), idx);
        if(idx == L.begin()+len+1){
            len++;
        }
    }
    
    int ans = len;

    cout << ans << '\n';

    dfs(N, len, P, v1);

    vector<int> ans2;
    for(int i = 1; i <= N; i++){
        if(v1[i] == 0) ans2.push_back(p1[i].second);
    }
    
    sort(ans2.begin(), ans2.end());

    for(int elem : ans2){
        cout << elem << ' ';
    }
    cout << '\n';
}
