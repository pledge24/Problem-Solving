#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

string s1, s2;

bool inRange(int i, int j){
    return 0 <= i && i < s1.length() && 0 <= j && j < s2.length();
}

int main() {
	fastio;
    cin >> s1 >> s2;

    vector<vector<int>> dp(s1.length(),vector<int>(s2.length()));

    int longest_len = 0;

    for(int i = 0; i < s1.length(); i++){
        for(int j = 0; j < s2.length(); j++){
            
            if(s1[i] == s2[j]){
                dp[i][j] = 1;
                //cout << "check" << '\n';
                //printf("i = %d, j = %d, (%d, %d)\n", i, j, s1[i], s2[j]);
                if(inRange(i-1, j-1)){
                    dp[i][j] += dp[i-1][j-1];
                }

                longest_len = max(longest_len, dp[i][j]);
            }

            
            
        } 
    }
    
    // print test.
    // for(int i = 0; i < s1.length(); i++){
    //     for(int j = 0; j < s2.length(); j++){
    //         cout << dp[i][j] << ' ';       
    //     } 
    //     cout << '\n';
    // }

    int ans  = longest_len;

    cout << ans  << '\n';
}