#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAXN 1024
#define DIGITS 10
#define DIV 1000000000
using namespace std;

bool inRange(int x){
    return 0 <= x && x < DIGITS;
}

int main() {
	fastio;
    int N; cin >> N;
    vector<vector<vector<int>>> dp;

    dp.resize(N+1, vector<vector<int>>(MAXN, vector<int>(DIGITS, 0)));

    for(int num = 1; num < DIGITS; num++){
        dp[1][pow(2, num)][num] = 1;
    }

    int next_bit_pattern;
    for(int n = 1; n < N; n++){
        for(int cur_bit_pattern = 0; cur_bit_pattern < MAXN; cur_bit_pattern++){
            for(int last_num = 0; last_num < DIGITS; last_num++){
                
                if(dp[n][cur_bit_pattern][last_num] == 0) continue;

                if(inRange(last_num+1)){
                    next_bit_pattern = cur_bit_pattern | (1 << (last_num+1));
                    dp[n+1][next_bit_pattern][last_num + 1] = (dp[n+1][next_bit_pattern][last_num + 1] + dp[n][cur_bit_pattern][last_num]) % DIV;
                }
                
                
                if(inRange(last_num-1)){
                    next_bit_pattern = cur_bit_pattern | (1 << (last_num-1));
                    dp[n+1][next_bit_pattern][last_num - 1] = (dp[n+1][next_bit_pattern][last_num - 1] + dp[n][cur_bit_pattern][last_num]) % DIV;
                }
                
            }
        }
    }
    
    int ans = 0;

    for(int num = 0; num < DIGITS; num++){
        //cout << ans << ' ';
        //cout << dp[1][2][num] << ' ';
        ans = (ans + dp[N][MAXN-1][num]) % DIV;
    }
    //cout << '\n';


    //cout << 2 + pow(2, 3) << '\n';
    cout << ans << '\n';
}