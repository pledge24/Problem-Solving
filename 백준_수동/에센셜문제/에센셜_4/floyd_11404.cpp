#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAXN 100'000'000
using namespace std;

int main() {
	fastio;
    int n, m; cin >> n >> m;

    vector<vector<int>> matrix;
    vector<vector<int>> shortest_path;
    matrix.resize(n+1, vector<int>(n+1, MAXN));
    shortest_path.resize(n+1, vector<int>(n+1));

    int src, dst, w;
    for(int i = 0; i < m; i++){
        cin >> src >> dst >> w;
        matrix[src][dst] = min(matrix[src][dst], w);
    }

    shortest_path = matrix;

    for(int k = 1; k <= n; k++){

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) continue;
                shortest_path[i][j] = min(shortest_path[i][j], shortest_path[i][k] + shortest_path[k][j]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            shortest_path[i][j] = shortest_path[i][j] == MAXN ? 0 : shortest_path[i][j];
            cout << shortest_path[i][j] << ' ';
        }
        cout << '\n';
    }

}