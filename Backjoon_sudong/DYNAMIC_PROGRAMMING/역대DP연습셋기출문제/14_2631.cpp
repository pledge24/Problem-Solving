#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;
    vector<int> v1(N+1);

    for(int i = 1; i <= N; i++){
        cin >> v1[i];
    }

    vector<int> dp_num(N+1);
    vector<int> dp(N+1);
    int curr_num;
    for(int i = 1; i <= N; i++){
        curr_num = v1[i];
 
        dp_num[curr_num] = max(dp_num[curr_num], *max_element(dp_num.begin(), dp_num.begin()+curr_num)+1);

        dp[i] = dp_num[curr_num];
    }

    // // print test.
    // for(int i = 1; i <= N; i++){
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';

    // 접근법 
    // 0. 적은 수의 이동으로 오름차순 정렬을 하기 위해선, 최장 증가 수열을 기준으로 나머지 수를 이동시키는 것이 최적이다.
    // -> 이미 정렬되어 있는 부분이고, 최장 증가 수열을 찾는다면, 이동해야 할 남은 수가 제일 적기 때문.
    // 1. 한 수를 옮겼을 때, 최장 증가 수열은 무조건 1 증가한다. 증가하지 않을수도, 2 이상 증가할 수도 없다.
    int longest_len = *max_element(dp.begin(), dp.end());

    int ans = N - longest_len;

    cout << ans << '\n';
}