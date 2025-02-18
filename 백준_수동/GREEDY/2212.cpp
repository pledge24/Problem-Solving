#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;

    int N; cin >> N;
    int K; cin >> K;

    vector<int> v1(N);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }
    sort(v1.begin(), v1.end());

    // 가장 적은 영역을 구하시오
    // 수신기 사이의 거리가 긴 부분을 제외하면 된다.
    vector<int> diff(N);
    for(int i = 1; i < N; i++){
        diff[i] = v1[i] - v1[i-1];
    }
    sort(diff.begin(), diff.end(), greater<int>());

    int dist = v1.back() - v1.front();

    for(int i = 0; i < min(N, K)-1; i++){
        dist -= diff[i];
    }

    int ans = dist;
    cout << ans << '\n';

    return 0;
}