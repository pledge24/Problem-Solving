#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct del_data{
    long long src;
    long long dst;
    long long n;
    bool operator<(const del_data& d) const{
        long long dist1 = dst - src;
        long long dist2 = d.dst - d.src;
        // if(dst == d.dst){
        //     return dist1 < dist2;
        // }
        
        return dst > d.dst;
    }
};

int main(void){
    fastio;
    long long N, C; cin >> N >> C;
    long long M; cin >> M;

    priority_queue<del_data> pq;
    for(long long i = 0; i < M; i++){
        long long s, t, n; cin >> s >> t >> n;
        pq.push({s, t, n});
    }

    long long ans = 0;
    vector<long long> v1(N+1);
    while(!pq.empty()){
        del_data d = pq.top(); pq.pop();

        //cout << "curDel_data " << d.src << " " << d.dst << " " << d.n << '\n';

        // 적재할 수 있는 최대 적재량을 구한다.
        long long maxLoad = 0;
        for(long long i = d.src; i < d.dst; i++){
            if(v1[i] != 0)
                maxLoad = max(maxLoad, v1[i]);
        }
        long long additionalLoad = min(C - maxLoad, d.n);
        ans += additionalLoad;

        for(long long i = d.src; i < d.dst; i++){
            v1[i] += additionalLoad;
        }

        // for(long long i = 1; i <= N; i++){
        //     cout << v1[i] << ' '; 
        // }
        // cout << '\n';
    }

    cout << ans << '\n';

    return 0;
}