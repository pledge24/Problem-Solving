#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int nC2(int N){
    return N * (N-1) / 2;
}

int main(void){
    fastio;
    int N, M; cin >> N >> M;

    map<vector<int>, int> m1;
    for(int i = 0 ; i < N; i++){
        vector<int> v1(M);
        for(int j = 0; j < M; j++){
            cin >> v1[j];
        }

        vector<int> sorted_v1(v1);
        sort(sorted_v1.begin(), sorted_v1.end());

        vector<int> seq;
        for(auto elem : v1){
            int rank = lower_bound(sorted_v1.begin(), sorted_v1.end(), elem) - sorted_v1.begin();
            seq.push_back(rank);
        }
        
        m1[seq]++;
    }

    int ans = 0;
    for(auto elem : m1){
        // vector<int> seq = elem.first;
        // for(int order : seq)
        //     cout << order << ' ';
        // cout << '\n';

        // cout << elem.second << '\n';
        ans += nC2(elem.second);
    }

    cout << ans << '\n';

    return 0;
}