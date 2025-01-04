#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct cmp{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        if(a.first == b.first)
            return a.second < b.second;

        return a.first > b.first;
    }
};

int main(void){
    fastio;

    int N, L; cin >> N >> L;
    // 덧대더라도 x방향으로 크게 널빤지를 둔다.
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for(int i = 0; i < N; i++){
        int s, t; cin >> s >> t;
        pq.push({s, t});
    }
    
    int cnt = 0;
    int end = pq.top().first;
    while(!pq.empty()){
        pair<int, int> p = pq.top(); pq.pop();
        // cout << p.first << " " << p.second << '\n';
        if(end >= p.second) continue;
        
        // 널빤지가 있는 시점이 시작 지점보다 앞이면 이동.
        if(end < p.first) end = p.first;
        
        int len = p.second - end;
        int div = len / L;
        int mod = (len % L) > 0;

        cnt += div + mod;
        end += (div + mod) * L;
    }

    int ans = cnt;

    cout << ans << '\n';

    return 0;
}