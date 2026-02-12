#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, D; 

struct pathData{
    int src;
    int dst;
    int len;

    bool operator<(const pathData& other){
        if(src != other.src)
            return src < other.src;

        if(dst != other.dst)
            return dst < other.dst;

        return len < other.len;
    }
};

void dfsUtil(const vector<pathData>& v1, int& ans, int idx, int curPos, int len){
    if(idx == v1.size()){
        len += (D - curPos);
        ans = min(ans, len);
        return;
    }

    // 선택을 하거나,
    if(curPos <= v1[idx].src){
        int nextLen = len + (v1[idx].src - curPos) + v1[idx].len;
        dfsUtil(v1, ans, idx+1, v1[idx].dst, nextLen);
    }

    // 하지 않거나,
    dfsUtil(v1, ans, idx+1, curPos, len);
}

void dfs(vector<pathData>& v1, int& ans){
    int nextIdx = 0;
    int curPos = 0;
    int len = 0;
    dfsUtil(v1, ans, nextIdx, curPos, len);
}

int main(void){
    fastio;
    cin >> N >> D;

    vector<pathData> v1;
    for(int i = 0; i < N; i++){
        int s, t, l; cin >> s >> t >> l;

        // 1) 도착이 D 이하여야함
        if(t > D)
            continue;
        
        // 2) 지름길이 더 짧아야함
        if(l >= t-s)
            continue;

        v1.push_back(pathData{s, t, l});
    }

    sort(v1.begin(), v1.end());

    int ans = D;
    dfs(v1, ans);

    cout << ans << '\n';

    return 0;
}