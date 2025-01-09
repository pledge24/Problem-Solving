#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    // 비용은 내림차, 고기 양 오름차
    if(a.first != b.first)
        return a.first > b.first;     // 내림차

    return a.second < b.second;       // 오름차
};

int main(void){
    fastio;
    int N, M; cin >> N >> M;

    vector<pair<int, int>> v1(N);
    int leftW = 0;
    for(int i = 0; i < N; i++){
        int w, cost;
        cin >> w >> cost;
        v1[i] = {cost, w};

        leftW += w;
    }

    sort(v1.begin(), v1.end(), cmp);

    // 정렬 결과 출력
    // for(auto it : v1){
    //     cout << it.first << " " << it.second << '\n';
    // }

    if(leftW < M){
        cout << -1 << '\n';
        return 0;
    }

    int ans = INT32_MAX;
    for(int i = 0; i < N; i++){
        int cost, w; tie(cost, w) = v1[i];
    
        // 현재 고기를 뺐을 때 양이 부족한 경우
        if(leftW - w < M){
            int totalCost = 0;
            int start = i;
            // cout << "start " << start << '\n';
            // cout << "cost " << cost << " w " << w << '\n';
            // 최종 비용 = 비용 * 같은 비용의 남은 고기 개수
            while(start < N && cost == v1[start].first){
                totalCost += cost;
                start++;
            }
            ans = min(ans, totalCost);
            break;
        }

        // 이전 비용을 저장(비싼거 하나 산게 더 쌀 수 있음)
        if(i+1 == N || (i+1 < N && cost != v1[i+1].first))
            ans = min(ans, cost);

        leftW -= w;
    }

    cout << ans << '\n';

    return 0;
}