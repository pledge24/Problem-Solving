#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    long long N; cin >> N;

    vector<long long> v1(N + 1);
    for(long long i = 1; i <= N; i++){
        cin >> v1[i];
    }

    sort(v1.begin(), v1.end());

    long long sum = 0;
    for(long long i = 1; i <= N; i++){
        sum += abs(v1[i] - i);
    }

    long long ans = sum;

    cout << ans << '\n';

    return 0;
}