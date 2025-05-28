#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N, X; cin >> N >> X;

    vector<int> v1(N);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    int visitedN = accumulate(v1.begin(), v1.begin() + X, 0);
    int maxN = visitedN;
    int cnt = 1;
    for(int i = X; i < N; i++){
        visitedN += (v1[i] - v1[i-X]);

        if(maxN < visitedN){
            maxN = visitedN;
            cnt = 1;            
        }
        else if(maxN == visitedN)
            cnt++;

    }

    if(maxN == 0)
        cout << "SAD" << '\n';
    else{
        cout << maxN << '\n';
        cout << cnt << '\n';
    }

    return 0;
}