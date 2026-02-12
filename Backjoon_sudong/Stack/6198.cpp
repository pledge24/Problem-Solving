#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;
    vector<int> v1(N);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    stack<pair<int, long long>> s; // height, cnt
    long long cnt = 0;
    for(int i = 0; i < N; i++){
        if(s.empty()){
            s.push(make_pair(v1[i], 0));
            continue;
        }

        if(s.top().first <= v1[i]){  // 오름차(같음 포함) 발견

            // 내림차 정렬이 될때까지 반복
            while(!s.empty() && s.top().first <= v1[i]){
                pair<int, long long> prevData = s.top(); s.pop();
                cnt += prevData.second;
        
                if(!s.empty())
                    s.top().second += prevData.second + 1;
            } 
            
        }

        s.push(make_pair(v1[i], 0));
    }

    // 남아있는 내림차 계산.
    while(!s.empty()){
        pair<int, long long> prevData = s.top(); s.pop();
        cnt += prevData.second;

        if(!s.empty())
            s.top().second += prevData.second + 1;
    }

    long long ans = cnt;

    cout << ans << '\n';

    return 0;
}