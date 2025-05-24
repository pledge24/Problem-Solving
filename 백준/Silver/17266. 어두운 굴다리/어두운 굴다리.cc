#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N, M; cin >> N >> M;

    vector<int> v1(M);
    for(int i = 0; i < M; i++){
        cin >> v1[i];
    }

    int leftSide = v1.front();
    int rightSide = N - v1.back();

    int ans = max(leftSide, rightSide);
    for(int i = 1; i < M; i++){
        int dist = v1[i] - v1[i-1];
        ans = max(ans, (dist+1)/2);
    }

    cout << ans << '\n';

    return 0;
}