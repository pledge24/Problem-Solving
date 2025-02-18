#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1'000'000'000
using namespace std;

void floyd(vector<vector<int>>& graph){
    int N = graph.size()-1;

    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(i == j) continue;

                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main(void){
    fastio;
    int n, m, r; cin >> n >> m >> r;

    vector<int> items(n+1);
    for(int i = 1; i <= n; i++){
        cin >> items[i];
    }

    vector<vector<int>> graph(n+1, vector<int>(n+1, INF));
    // i -> i 는 이동 거리 0
    for(int i = 1; i <= n; i++){
        graph[i][i] = 0;
    }

    for(int i = 0; i < r; i++){
        int s, t, cost; cin >> s >> t >> cost;
        graph[s][t] = cost;
        graph[t][s] = cost;
    }

    // {
    //     for(int i = 1; i <= n; i++){
    //         for(int j = 1; j <= n; j++){
    //             cout << graph[i][j] << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }
    floyd(graph);

    int ans = 0;
    for(int src = 1; src <= n; src++){
        int sum = 0;
        for(int dst = 1; dst <= n; dst++){
            sum += graph[src][dst] <= m ? items[dst] : 0;
        }
        ans = max(ans, sum);
    }

    cout << ans << '\n';

    return 0;
}