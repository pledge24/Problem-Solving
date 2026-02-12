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

    // for(int elem : v1)
    //     cout << elem << ' ';
    // cout << '\n';

    long long ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            int sum = v1[i] + v1[j];
            if(binary_search(v1.begin()+j+1, v1.end(), -sum)){
                // printf("%d %d\n", v1[i], v1[j]);
                auto lower = lower_bound(v1.begin()+j+1, v1.end(), -sum);
                auto upper = upper_bound(v1.begin()+j+1, v1.end(), -sum);
                ans += upper - lower;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}