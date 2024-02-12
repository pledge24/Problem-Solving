#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N;

bool inRange(int i, int j){
    return 0 < i && i <= N && 0 < j && j <= N;
}

int main() {
	fastio;
     cin >> N;

    // input
    vector<vector<int>> matrix(N+1, vector<int>(N+1));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> matrix[i][j];
        }
    }
    
    vector<vector<long long>> dp(N+1, vector<long long>(N+1));
    dp[1][1] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int jump_n = matrix[i][j];
            if(jump_n != 0){
                if(inRange(i+jump_n, j)){
                dp[i+jump_n][j] += dp[i][j];
                }

                if(inRange(i, j+jump_n)){
                    dp[i][j+jump_n] += dp[i][j];
                }
            }
            

            // // print test.
            // for(int i = 1; i <= N; i++){
            //     for(int j = 1; j <= N; j++){
            //         cout << dp[i][j] << ' ';
            //     }
            //     cout << '\n';
            // }
            // cout << '\n';
        }

        
    }

    


    long long ans = dp[N][N];

    cout << ans << '\n';
}