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
    sort(v1.begin(), v1.end());

    int totalCost; cin >> totalCost;
    int ans = v1.back();
    for(int i = 0; i < N; i++){
        int cost = v1[i];
        int leftN = N - i;
        if(totalCost <= cost*leftN){
            ans = totalCost / leftN;
            break;
        }
        totalCost -= cost;
    }

    cout << ans << '\n';

    return 0;
}