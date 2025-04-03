#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Graph = vector<vector<int>>;

void dfs(Graph& graph, vector<bool>& visited, int cur, int& totalEdges){
    for(int adj : graph[cur]){
        if(!visited[adj]){
            totalEdges++;
            visited[adj] = true;
            dfs(graph, visited, adj, totalEdges);
        }
    }
}

int main(void){
    fastio;
    int N, M; cin >> N >> M;
    Graph graph(N+1);
    for(int i = 0; i < M; i++){
        int A, B; cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    vector<bool> visited(N+1);
    int graphN = 0;
    int totalEdges = 0;
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            graphN++;
            visited[i] = true;
            dfs(graph, visited, i, totalEdges);
        }
    }

    int removeN = M - totalEdges;
    int addN = graphN-1;

    // cout << removeN << " " << addN << '\n';

    cout << removeN + addN << '\n';

    return 0;
}