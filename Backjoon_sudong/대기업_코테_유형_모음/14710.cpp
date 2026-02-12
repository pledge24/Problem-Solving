#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int H, W; cin >> H >> W;

    vector<int> v1(W);
    for(int i = 0; i < W; i++){
        int h; cin >> v1[i];
    }

    vector<int> backMax(W);
    int maxH = 0;
    for(int i = W-1; i >= 0; i--){
        maxH = max(maxH, v1[i]);
        backMax[i] = maxH;
    }

    int total = 0;
    int leftMaxH = 0;
    for(int i = 0; i < W; i++){
        total += max(min(leftMaxH, backMax[i]) - v1[i], 0);

        leftMaxH = max(leftMaxH, v1[i]);
    }

    cout << total << '\n';
    
    return 0;
}