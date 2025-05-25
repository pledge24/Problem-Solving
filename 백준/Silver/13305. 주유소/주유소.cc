#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using int64 = long long;

int main(void){
    fastio;
    int64 N; cin >> N;

    vector<int64> dist(N-1);
    for(int64 i = 0; i < dist.size(); i++){
        cin >> dist[i];
    }

    int64 minCost = INT64_MAX;
    int64 totalCost = 0;
    for(int64 i = 0; i < N-1; i++){
        int64 cost; cin >> cost;
        minCost = min(cost, minCost);
        totalCost += minCost * dist[i];
    }

    cout << totalCost << '\n';
    
    return 0;
}