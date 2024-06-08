#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAXN 100

using namespace std;

int dp[MAXN+1][MAXN+1][MAXN+1];
string a, b, c;


int main() {
	fastio;

    cin >> a >> b >> c;
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            for (int k = 1; k <= c.length(); k++) {
                if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else {
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k-1]});
                }
            }
            

        }

    }
  
    // for (int i = 1; i <= a.length(); i++) {
    //     for (int j = 1; j <= b.length(); j++) {
    //         for (int k = 1; k <= c.length(); k++) {
    //             cout << dp[i][j][k] << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }

    int ans = dp[a.length()][b.length()][c.length()];
    cout << ans << '\n';
    
}