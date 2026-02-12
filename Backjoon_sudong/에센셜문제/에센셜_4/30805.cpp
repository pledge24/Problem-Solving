#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Sequnce = vector<int>;

int main(void){
    fastio;
    int N; cin >> N;
    vector<int> v1(N+1);
    for(int i = 1; i <= N; i++){
        cin >> v1[i];
    }

    int M; cin >> M;
    vector<int> v2(M+1);
    for(int i = 1; i <= M; i++){
        cin >> v2[i];
    }

    // 가장 사전순이 느린것은?
    // 시작수: 머리에 있는 값
    // 현재수: 이어진 값.
    vector<vector<Sequnce>> dp(N+1, vector<Sequnce>(M+1));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(v1[i] == v2[j]){ // matching
                Sequnce seq = dp[i-1][j-1];
                auto idx = upper_bound(seq.begin(), seq.end(), v1[i], greater<int>());
                Sequnce A(seq.begin(), idx); A.push_back(v1[i]);
                Sequnce B = dp[i-1][j];
                Sequnce C = dp[i][j-1];

                dp[i][j] = max({A, B, C});
            }
            else{
                Sequnce B = dp[i-1][j];
                Sequnce C = dp[i][j-1];
                dp[i][j] = max(B, C);
            }

        }
    }


    // for(int i = 1; i <= N; i++){
    //     for(int j = 1; j <= M; j++){
    //         for(int elem : dp[i][j])
    //             cout << elem << ' ';
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }

    cout << dp[N][M].size() << '\n';

    for(int elem : dp[N][M])
        cout << elem << ' ';
    cout << '\n';

    return 0;
}