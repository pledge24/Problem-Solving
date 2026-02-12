#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;


int main(void){
    fastio;
    int N; cin >> N;
    vector<vector<int>> matrix(N+1, vector<int>(N+1));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> matrix[i][j];
        }
    }

    struct posData{
        int rows = 0;
        int cols = 0;
        int dias = 0;
    };

    vector<vector<posData>> dp(N+1, vector<posData>(N+1));
    dp[1][2] = {1, 0, 0};
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(matrix[i][j] == 1 || (i == 1 && j == 2))
                continue;

            dp[i][j].rows = dp[i][j-1].rows + dp[i][j-1].dias;
            dp[i][j].cols = dp[i-1][j].cols + dp[i-1][j].dias;
            
            if(matrix[i-1][j] == 1 || matrix[i][j-1] == 1 || matrix[i-1][j-1] == 1)
                continue;
            dp[i][j].dias = dp[i-1][j-1].rows + dp[i-1][j-1].cols+ dp[i-1][j-1].dias;
        }
    }

    int ans = dp[N][N].rows + dp[N][N].cols + dp[N][N].dias;

    cout << ans << '\n';

    // for(int i = 1; i <= N; i++){
    //     for(int j = 1; j <= N; j++){
    //         cout << dp[i][j].rows + dp[i][j].cols+ dp[i][j].dias << " ";
    //     }
    //     cout << '\n';
    // }
    return 0;
}