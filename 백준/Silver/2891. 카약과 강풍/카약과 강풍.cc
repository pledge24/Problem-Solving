#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, S, R; 

bool inRange(int x){
    return 1 <= x && x <= N;
}

int main(void){
    fastio;
    cin >> N >> S >> R;
    vector<int> v1(N+1, 1);

    // 1) 카약은 왼쪽 또는 오른쪽 사람에게 빌려줄 수 있다.
    // 2) 여분의 카약만 빌려줄 수 있다.
    for(int i = 0; i < S; i++){
        int teamId; cin >> teamId;
        v1[teamId]--;
    }

    for(int i = 0; i < R; i++){
        int teamId; cin >> teamId;
        v1[teamId]++;
    }

    int zeroN = 0;
    for(int i = 1; i <= N; i++){
        if(v1[i] > 0)
            continue;

        // 카약이 없을때 왼쪽 또는 오른쪽에게 빌린다.
        if(inRange(i-1) && v1[i-1] > 1){
            v1[i-1]--;
            v1[i]++;
            continue;
        }

        if(inRange(i+1) && v1[i+1] > 1){
            v1[i+1]--;
            v1[i]++;
            continue;
        }

        zeroN++;
    }

    int ans = zeroN;

    cout << ans << '\n';

    return 0;
}