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

    stack<pair<int, int>> s; // num, idx
    vector<int> ans(N, -1);
    for(int i = 0; i < N; i++){
        if(s.empty()){
            s.push(make_pair(v1[i], i)); 
            continue;
        }

        // 오름차 발견 시, 내림차(같은 값 포함) 유지될때까지 오큰수 구함.
        while(!s.empty() && s.top().first < v1[i]){
            ans[s.top().second] = v1[i];
            s.pop();
        }   
        
        s.push(make_pair(v1[i], i)); 
    }

    // print answer.
    for(int i = 0; i < N; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}