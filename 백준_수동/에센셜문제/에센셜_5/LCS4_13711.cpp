#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N;

int main() {
	fastio;

    cin >> N;

    vector<int> a(N+1);
    vector<int> b(N+1);

    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= N; i++){
        cin >> b[i];
    }

    vector<int> cur_row_dp(N+1);  
    for (int i = 1; i <= N; i++) {
        vector<int> next_row_dp(N+1);
        for (int j = 1; j <= N; j++) {
            if (a[i] == b[j]) {
                next_row_dp[j] = cur_row_dp[j-1] + 1;

            }
            else {
                next_row_dp[j] = max(cur_row_dp[j], next_row_dp[j-1]);
            }

        }
        swap(cur_row_dp, next_row_dp);
        //next_row_dp.clear();
    }

    int ans = cur_row_dp[N];
    cout << ans << '\n';
    
}