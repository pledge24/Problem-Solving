#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Matrix = vector<vector<int>>;

const long long DIV = 1e9+7;
const int MAXLEN = 7;
const int MAXN = 100'000;

long long dp[MAXN+1][MAXLEN+1];

long long dfs(Matrix& matrix, int idx, int depth){
    long long res = 0;

    if(depth == MAXLEN)
        return 1;
        
    if(dp[idx][depth] > 0)
        return dp[idx][depth];

    vector<int>& adj = matrix[idx];
    for(int elem : adj){
        res = (res + dfs(matrix, elem, depth+1)) % DIV;
    }

    dp[idx][depth] = res;

    return res;
}

int main(void){
    fastio;
    int N, M; cin >> N >> M;

    Matrix matrix(N+1);
    for(int i = 0; i < M; i++){
        int s, t; cin >> s >> t;
        matrix[s].push_back(t);
        matrix[t].push_back(s);
    }

    long long ans = 0;
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= N; i++){
        ans = (ans + dfs(matrix, i, 0)) % DIV;
    }

    cout << ans << '\n';

    return 0;
}