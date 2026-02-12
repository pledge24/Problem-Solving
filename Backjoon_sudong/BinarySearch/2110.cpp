#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using posData = pair<int, int>;

int main(void){
    fastio;
    int N, C; cin >> N >> C;

    vector<int> v1(N);
    set<int> s1;
    for(int i = 0; i < N; i++){
        cin >> v1[i];
        s1.insert(v1[i]);
    }

    priority_queue<posData, vector<posData>, greater<posData>> pq; // dist(left-side), idx
    int prevPos = *s1.begin();
    bool isFirst = true;
    for(auto pos : s1){
        if(isFirst){
            isFirst = false;
            continue;
        }

        int dist = pos - prevPos;
        pq.push(make_pair(dist, pos));
        prevPos = pos;
    }

    int removeN = N - C;
    while(removeN > 0){
        posData posData = pq.top(); pq.pop();

        int dist = posData.first;
        int pos = posData.second;

        auto it = s1.find(pos);
        // 1) 거리 갱신이 되지 않은 경우
        if(it != s1.begin()){
            auto prevIt = std::prev(it);
            int ExpectedDist = *it - *prevIt;
            if(dist != ExpectedDist){
                pq.push(make_pair(ExpectedDist, pos));
                continue; // loop back
            }

        }

        // 2) 거리 갱신이 된 경우(또는 문제가 없는 경우)
        s1.erase(pos);
        cout << "removePos: " << pos << '\n';

        removeN--;
    }

    auto it = s1.begin();
    advance(s1.begin(), 2);
    isFirst = true;
    int ans = INT32_MAX;
    int prev = -1;
    for(auto elem : s1){
        if(isFirst){
            isFirst = false;
            prev = elem;
            continue;
        }

        ans = min(ans, elem - prev);
        prev = elem;

        // cout << "elem: " << elem << '\n';
    }

    cout << ans << '\n';

    return 0;
}