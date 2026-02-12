#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 3

using namespace std;
using Matrix = vector<vector<int>>;

int dy[DIR] = {-1, 0, 1};
int N, M; 

void DfsUtil(Matrix& matrix, int curDepth, int y, int& res, int cost, int dir){
    if(curDepth + 1 == N){
        res = min(res, cost);
        return;
    }

    for(int i = 0; i < DIR; i++){
        if(dir == i)
            continue;

        int ny = y + dy[i];
        if(0 <= ny && ny < M){
            DfsUtil(matrix, curDepth+1, ny, res, cost + matrix[curDepth+1][ny], i);
        }
    }
}

int Dfs(Matrix& matrix){
    int res = INT32_MAX;
    for(int i = 0; i < M; i++){
        DfsUtil(matrix, 0, i, res, matrix[0][i], -1);
    }

    return res;
}

int main(void){
    fastio;

    cin >> N >> M;

    Matrix matrix(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> matrix[i][j];
        }
    }

    int ans = Dfs(matrix);

    cout << ans << '\n';

    return 0;
}