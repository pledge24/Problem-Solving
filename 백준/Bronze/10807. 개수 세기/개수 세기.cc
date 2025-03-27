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

    int target; cin >> target;
    int ans = count(v1.begin(), v1.end(), target);

    cout << ans << '\n';

    return 0;
}