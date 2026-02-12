#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Egg = pair<int, int>; // hp, weight

int maxN = 0;

void Backtracking(vector<Egg>& v1, int idx){
    // cout << idx << '\n';
    // 종료 조건.
    int leftN = count_if(v1.begin(), v1.end(), [](Egg egg){ return egg.first > 0;});
    if(idx >= v1.size() || leftN < 2){
        maxN = max(maxN, (int)(v1.size() - leftN));
        return;
    }

    for(int i = 0; i < v1.size(); i++){

        // 계란 치기
        if(v1[i].first > 0 && i != idx){

            v1[idx].first -= v1[i].second;
            v1[i].first -= v1[idx].second;
            
            {
                // find not destroyed egg.
                int nextIdx = idx+1;
                while(nextIdx < v1.size() && v1[nextIdx].first <= 0)
                    nextIdx++;
    
                Backtracking(v1, nextIdx);
            }

            v1[idx].first += v1[i].second;
            v1[i].first += v1[idx].second;
        }
    }
}

int main(void){
    fastio;
    int N; cin >> N;

    vector<Egg> v1(N);
    for(int i = 0; i < N; i++){
        int hp, weight; cin >> hp >> weight;
        v1[i] = make_pair(hp, weight);
    }

    Backtracking(v1, 0/*시작 계란 idx*/);
    
    cout << maxN << '\n';

    return 0;
}