#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

bool isGoodNum(vector<int>& v1, int idx){
    int e = v1.size()-1;
    for(int s = 0; s < e; s++){
        if(s == idx) continue;

        while(s < e && (v1[s] + v1[e] > v1[idx] || e == idx)){
            e--;
        }
        if(s >= e) break;
        if(v1[s] + v1[e] == v1[idx]) return true;
    }

    return false;
}

int main() {
	fastio;
    int N; cin >> N;

    vector<int> v1(N);
    for(int i = 0; i < N; i++) cin >> v1[i];
    sort(v1.begin(), v1.end());
    
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(isGoodNum(v1, i)) ans++;
    }

    cout << ans << '\n';
}