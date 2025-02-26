#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;
    vector<int> v1(N+1);
    for(int i = 1; i <= N; i++){
        cin >> v1[i];
    }

    vector<int> ans(N+1);
    stack<pair<int, int>> s;    // idx, num
    for(int i = N; i > 0; i--){
        if(s.empty()){
            s.push(make_pair(i, v1[i]));
            continue;
        }

        pair<int, int> prevData = s.top(); 
        if(v1[i] > prevData.second){    // ex. v1[i] = 9, prevNum = 3
            while(!s.empty() && v1[i] > s.top().second){
                ans[s.top().first] = i;
                s.pop();
            }
        }

        s.push(make_pair(i, v1[i]));
        
    }

    for(int i = 1; i <= N; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}