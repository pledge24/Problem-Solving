#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIV 1'000'000'007

using namespace std;

int main(void)
{
    fastio;

    const int maxN = 10000;
    vector<vector<int>> dp(maxN+1, vector<int>(7));
    dp[1] = {1, 2, 2, 1, 1, 1, 1};
    for(int i = 2; i <= maxN; i++)
    {
        vector<int>& prev = dp[i-1];
        vector<int>& cur = dp[i];

        for(int mod = 0; mod < 7; mod++)
        {
            for(int digit = 0; digit <= 9; digit++)
            {
                cur[(mod + digit) % 7] = (cur[(mod + digit) % 7] + prev[mod]) % DIV;
            }
        }

        // for(int elem : cur)
        //     cout << elem << ' ';
        // cout << '\n';
    }

    // Except 7
    vector<vector<int>> dp2(maxN+1, vector<int>(7));
    dp2[1] = {0, 2, 2, 1, 1, 1, 1};
    for(int i = 2; i <= maxN; i++)
    {
        vector<int>& prev = dp2[i-1];
        vector<int>& cur = dp2[i];

        for(int mod = 0; mod < 7; mod++)
        {
            for(int digit = 0; digit <= 9; digit++)
            {
                if(digit == 7 || digit == 0)
                    continue;

                cur[(mod + digit) % 7] = (cur[(mod + digit) % 7] + prev[mod]) % DIV;
            }
        }
    }

    // Process
    int T; cin >> T;
    for(int i = 0; i < T; i++)
    {
        int N; cin >> N;

        int ans = dp[N][0] - dp2[N][0];
        if(ans < 0)
            ans += DIV;

        cout << ans << '\n';
    }

    return 0;
}