#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;

    vector<pair<int, int>> v1;
    for(int i = 0; i < N; i++){
        int L, H; cin >> L >> H;
        v1.push_back(make_pair(L, H));
    }

    sort(v1.begin(), v1.end());

    auto maxIt = max_element(v1.begin(), v1.end(), 
        [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second < p2.second;
    });

    

    int ans = 0;
    // 오르막길
    {
        pair<int, int> prev = v1[0];
        for(auto it = v1.begin(); it <= maxIt; it++){
            int w = it->first - prev.first;
            int h = prev.second;

            // cout << "(w, h)" << w << " " << h << '\n';
            ans += w*h;

            prev = make_pair(it->first, max(it->second, prev.second));
        }
    }
    ans += maxIt->second;

    vector<int> maxV1(N);
    int maxH = 0; 
    for(int i = N-1; i >= 0; i--){
        maxH = max(maxH, v1[i].second);
        maxV1[i] = maxH;
    }

    // 내리막길
    {
        pair<int, int> prev = *maxIt;
        for(auto it = maxIt; it != v1.end(); it++){
            int idx = it - v1.begin();
            int w = it->first - prev.first;
            int h = maxV1[idx];

            ans += w*h;

            prev = make_pair(it->first, h);
        }
    }
    

    cout << ans << '\n';
    
    return 0;
}