#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;

int M, N;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

vector<vector<int>> matrix;
vector<vector<bool>> visited_data;
vector<vector<long long>> dp;

bool inRange(int m, int n){
    return 0 < m && m <= M && 0 < n && n <= N;
}

long long memolization(int m, int n){

    // 이미 경우의 수를 구한경우(방문은 했지만 경우의 수가 없는경우 포함(visited가 true인데 값이 0인 경우)).
    if(visited_data[m][n]){
        return dp[m][n];
    }
    
    visited_data[m][n] = true;

    // 처음 방문한 경우
    for(int i=0; i<DIR; i++){
        int nx = m + dx[i];
        int ny = n + dy[i];

        if(inRange(nx, ny) && (matrix[m][n] < matrix[nx][ny])){
            
            dp[m][n] += memolization(nx, ny);
            
        }
    }

    return dp[m][n];
}

int main() {
	fastio;
    cin >> M >> N;

    matrix.resize(M+1, vector<int>(N+1));
    visited_data.resize(M+1, vector<bool>(N+1));

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
    
    dp.resize(M+1, vector<long long>(N+1));

    dp[1][1] = 1;

    long long ans  = memolization(M, N);

    // // print test.
    // for(int m = 1; m <= M; m++){
    //     for(int n = 1; n <= N; n++){
    //         cout << dp[m][n] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << ans << '\n';

    return 0;
}
        


    

    


