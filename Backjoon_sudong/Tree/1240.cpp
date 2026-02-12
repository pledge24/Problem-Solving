#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Graph = vector<vector<pair<int, int>>>;

int X = 0;

void dfs(Graph& graph, vector<bool>& visited, int cur, int tgt, int& distance){
    if(cur == tgt){
        X = distance;
        return;
    }

    for(auto adj : graph[cur]){
        if(!visited[adj.first]){
            distance += adj.second;
            visited[adj.first] = true;

            dfs(graph, visited, adj.first, tgt, distance);

            distance -= adj.second;
        }
    }
}

int main(void){
    fastio;
    int N, M; cin >> N >> M;

    Graph graph(N+1);
    for(int i = 0; i < N-1; i++){
        int A, B, W; cin >> A >> B >> W;
        graph[A].push_back(make_pair(B, W));
        graph[B].push_back(make_pair(A, W));
    }    

    for(int i = 0; i < M; i++){
        int A, B; cin >> A >> B;
        vector<bool> visited(N+1);
        X = 0;
        int distance = 0;
        visited[A] = true;
        dfs(graph, visited, A, B, distance);
        cout << X << '\n';
    }

    return 0;
}