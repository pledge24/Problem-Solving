#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void startTest(){
    int N; cin >> N;

    vector<int> v1(N);
    map<int, int> m1; // teamId, cnt
    for(int i = 0; i < N; i++){
        cin >> v1[i];
        m1[v1[i]]++;
    }

    int score = 1;
    map<int, vector<int>> m2;
    for(int elem : v1){
        if(m1[elem] < 6)
            continue;
        
        m2[elem].push_back(score);

        score++;
    }

    int ans = -1;
    pair<int, int> minScore = make_pair(INT32_MAX, INT32_MAX);
    for(auto elem : m2){
        vector<int>& vx = elem.second;

        int totalScore = accumulate(vx.begin(), vx.begin()+4, 0);

        pair<int, int> temp = make_pair(totalScore, vx[4]);
        if(temp < minScore){
            minScore = temp;
            ans = elem.first;
        }
    }

    cout << ans << '\n';

}

int main(void){
    fastio;
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        startTest();
    }

    return 0;
}