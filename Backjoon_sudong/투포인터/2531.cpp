#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N, d, k, c; cin >> N >> d >> k >> c;

    vector<int> belts(N+1);
    for(int i = 1; i <= N; i++){
        cin >> belts[i];
    }

    // k개를 먹었을때 가짓수의 최댓값?
    map<int, int> sushiType;

    // init
    for(int i = 1; i <= k; i++){
        sushiType[belts[i]]++;
    }

    int maxTypes = sushiType.size() + (sushiType.find(c) == sushiType.end());

    for(int i = 1; i <= N; i++){
        int pushIdx = k+i > N ? k+i-N : k+i; 
        int popIdx = i;

        // push
        sushiType[belts[pushIdx]]++;

        // pop
        sushiType[belts[popIdx]]--;
        if(sushiType[belts[popIdx]] == 0)
            sushiType.erase(belts[popIdx]);

        maxTypes = max(maxTypes, (int)(sushiType.size() + (sushiType.find(c) == sushiType.end())));
    }

    cout << maxTypes << '\n';

    return 0;
}