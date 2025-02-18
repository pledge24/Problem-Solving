#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;

    vector<pair<long long, long long>> v1(N);
    long long totalPeople = 0;
    for(int i = 0; i < N; i++){
        long long townNum, people;
        cin >> townNum >> people;
        v1[i] = {townNum, people};
        totalPeople += people;
    }

    sort(v1.begin(), v1.end());

    long long minPos = v1[0].first;
    long long prevPeople = v1[0].second;
    long long minGap = totalPeople - v1[0].second;
    for(int i = 1; i < N; i++){
        pair<long long, long long> p = v1[i];
        long long left = prevPeople;
        long long right = totalPeople - left;

        // 현재 위치로 이동하면 손해보는 경우
        // 손해와 이득이 같을 경우 이동하지 않는다.
        if(left >= right){
            break;
        }

        // 현재 위치로 이동해도 이득보는 경우
        minPos = p.first;
        prevPeople += p.second;
    }

    long long ans = minPos;
    
    cout << ans << '\n';

    return 0;
}