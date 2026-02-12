#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAXNUM 100000000

using namespace std;

int main() {
	fastio;
    int N; cin >> N;
    vector<vector<int>> matrix;
    matrix.resize(N, vector<int>(N));

    // input data.
    int num = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){          
            cin >> num;
            num = num > 0 ? num : MAXNUM;
            matrix[i][j] = num;
        }
    }
    
    int dp_rows = pow(2, N);
    int dp_cols = N;

    vector<vector<vector<int>>> dp;
    dp.resize(N+1, vector<vector<int>>(dp_rows, vector<int>(dp_cols, MAXNUM)));

    // init
    for(int i = 1; i < N; i++){
        dp[1][1 + (1 << i)][i] = matrix[0][i];
    }
    
    int next_bit_patterns;
    // n: 방문한 도시 수(0번 도시 제외)
    // cur_bit_patterns: 방문한 도시 데이터 패턴
    // last_v: 마지막으로 방문한 도시 번호.
    // k: 특정 상황에서 방문하지 않은 도시 번호
    for(int n = 2; n < N; n++){
        for(int cur_bit_patterns = 1; cur_bit_patterns < dp_rows; cur_bit_patterns++){
            for(int last_v = 1; last_v < dp_cols; last_v++){
                if(dp[n-1][cur_bit_patterns][last_v] == MAXNUM) continue;

                for(int k = 1; k < dp_cols; k++){
                    // 방문한 도시는 pass
                    if((cur_bit_patterns >> k) % 2 == 1) continue;

                    next_bit_patterns = cur_bit_patterns | (1 << k);
                    //cout << dp[n][next_bit_patterns][k] << '\n';
                    dp[n][next_bit_patterns][k] = min(dp[n][next_bit_patterns][k], dp[n-1][cur_bit_patterns][last_v] + matrix[last_v][k]);
                }
            }
        }
    }
    
    for(int i = 1; i < dp_cols; i++){
        dp[N][dp_rows-1][i] = dp[N-1][dp_rows-1][i] + matrix[i][0];
    }

    int ans = *min_element(dp[N][dp_rows-1].begin(), dp[N][dp_rows-1].end());

    cout << ans << '\n';

}