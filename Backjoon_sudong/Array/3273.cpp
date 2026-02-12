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
    int desired; cin >> desired;

    sort(v1.begin(), v1.end());

    int end = N-1;
    int cnt = 0;
    for(int start = 0; start < end; start++){
        while(start < end && v1[start] + v1[end] > desired)
            end--;

        if(start != end && v1[start] + v1[end] == desired)
            cnt++;
    }

    int ans = cnt;

    cout << ans << '\n';

    return 0;
}