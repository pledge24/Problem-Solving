#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAXN 1000

using namespace std;

vector<vector<int>> dp(MAXN+1, vector<int>(MAXN+1));
string a, b;

string getLCS(){
    int cur_r = a.length();
    int cur_c = b.length();

    string lcs = "";

    while(cur_r > 0 && cur_c > 0){

        if(a[cur_r-1] == b[cur_c-1]){
            lcs = a[cur_r-1] + lcs;
            cur_r--;
            cur_c--;
        }
        else{
            if(dp[cur_r][cur_c-1] > dp[cur_r-1][cur_c]){
                cur_c--;
            }
            else{
                cur_r--;
            }
        }
    }

    return lcs;
}

int main() {
	fastio;

    cin >> a >> b;
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

        }

    }

    // for (int i = 1; i <= a.length(); i++) {
    //     for (int j = 1; j <= b.length(); j++) {
    //         cout << dp[i][j] << ' ';

    //     }
    //     cout << '\n';

    // }
    int ans = dp[a.length()][b.length()];
    cout << ans << '\n';
    
    cout << getLCS() << '\n';
}