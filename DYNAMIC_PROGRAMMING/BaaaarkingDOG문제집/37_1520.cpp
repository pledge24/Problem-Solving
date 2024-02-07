#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int M, N;

bool inRange(int m, int n){
    return 0 < m && m <= M && 0 < n && n <= N;
}
int main() {
	fastio;
    cin >> M >> N;

    vector<vector<int>> matrix;
    matrix.resize(M+1, vector<int>(N+1));

    for(int m = 1; m <= M; m++){
        for(int n = 1; n <= N; n++){
            cin >> matrix[m][n];
        }
    }

    // // print
    // for(int m = 1; m <= M; m++){
    //     for(int n = 1; n <= N; n++){
    //         cout << matrix[m][n] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    vector<vector<long long>> dp;
    dp.resize(M+1, vector<long long>(N+1));

    dp[1][1] = 1;
    for(int m = 1; m <= M; m++){

        
        vector<long long> dp_to_right(N+1);
        vector<long long> dp_to_left(N+1);
        for(int n = 1; n <= N; n++){

            // 맨 윗줄은 그냥 ㄱ
            if(m == 1 && inRange(m, n-1) && matrix[m][n-1] > matrix[m][n]){
                dp[m][n] = dp[m][n-1];
                continue;
            }

            if(n == 1){
                dp_to_right[1] = matrix[m-1][n] > matrix[m][n] ? dp[m-1][1]: 0;
                dp_to_left[N] = matrix[m-1][n] > matrix[m][n] ? dp[m-1][N]: 0;
            }
            else{
                if(inRange(m-1, n) && matrix[m-1][n] > matrix[m][n]){
                    dp_to_right[n] += dp[m-1][n];
                }
                if(inRange(m, n-1) && matrix[m][n-1] > matrix[m][n]){
                    dp_to_right[n] += dp[m][n-1];
                }

                if(inRange(m-1, n) && matrix[m-1][n] > matrix[m][n]){
                    dp_to_left[N-n+1] += dp[m-1][n];
                }
                if(inRange(m, n-1) && matrix[m][n-1] > matrix[m][n]){
                    dp_to_left[N-n+1] += dp[m][n-1];
                }
            }
            

        }

        cout << "dp_to_right: ";
        for(int i = 1; i<=N; i++){
            cout << dp_to_right[i] << ' ';
        }
        cout << '\n';

        cout << "dp_to_left: "; 
        for(int i = 1; i<=N; i++){
            cout << dp_to_left[i] << ' ';
        }
        cout << '\n';

        if(m != 1){
            for(int n = 1; n <= N; n++){
                dp[m][n] = dp_to_left[n] + dp_to_right[n];
            }
        }
        


    }

    long long ans = dp[M][N];

    cout << ans << '\n';

    for(int m = 1; m <= M; m++){
        for(int n = 1; n <= N; n++){
            cout << dp[m][n] << ' ';
        }
        cout << '\n';
    }
}

