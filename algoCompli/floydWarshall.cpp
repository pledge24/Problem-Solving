#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAXN 100'000'000
using namespace std;

void floyd(int N, vector<vector<int>>& graph, vector<vector<vector<int>>>& dist){
    dist[0] = graph; // dist 초기화

    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(i == j) continue;

                dist[k][i][j] = min(dist[k-1][i][j], dist[k-1][i][k] + dist[k-1][k][j]);
            }
        }
    }
}

void floyd2(int N, vector<vector<int>>& graph, vector<vector<int>>& dist){
    dist = graph; // dist 초기화

    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(i == j) continue;

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void floyd2(int N, vector<vector<int>>& graph, vector<vector<int>>& dist, vector<vector<int>>& path){
    dist = graph; // dist 초기화

    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(i == j) continue;
                
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    path[i][j] = k;
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void printPath(vector<vector<int>>& path, int r, int c){
    if(path[r][c] != 0){
        printPath(path, r, path[r][c]);
        cout << path[r][c] << " ";
        printPath(path, path[r][c], c);
    }
}

int main() {
	fastio;
    int N, M; cin >> N >> M;

    vector<vector<vector<int>>> graphBig;
    vector<vector<int>> graph;
    vector<vector<int>> dist;
    vector<vector<int>> path;

    graphBig.resize(N+1, vector<vector<int>>(N+1, vector<int>(N+1, MAXN)));
    graph.resize(N+1, vector<int>(N+1, MAXN));
    dist.resize(N+1, vector<int>(N+1));
    path.resize(N+1, vector<int>(N+1));

    int src, dst, w;
    for(int i = 0; i < M; i++){
        cin >> src >> dst >> w;
        graph[src][dst] = min(graph[src][dst], w);
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            dist[i][j] = dist[i][j] == MAXN ? 0 : dist[i][j];
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

}