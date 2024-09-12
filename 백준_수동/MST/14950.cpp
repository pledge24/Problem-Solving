#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct edgeData{
    int vertexNo;
    int weight;
};

struct cmp
{
    bool operator()(const edgeData& a, const edgeData& b){
        return a.weight > b.weight;
    }
};

int prim_algorithm(vector<vector<edgeData>> graph, int N, int t){
    int edge_sum = 0;
    vector<bool> visited;
    visited.resize(N+1);

    priority_queue<edgeData, vector<edgeData>, cmp> pq;

    int nextVertexNo = 1;
    int cnt = 0;
    for(int x = 0; x < N-1; x++){
       
        visited[nextVertexNo] = true;

        for(edgeData ed : graph[nextVertexNo]){
			if(!visited[ed.vertexNo]) pq.push(ed);     
        }

        while(!pq.empty()){
            edgeData cur_edge = pq.top(); pq.pop();
            if(!visited[cur_edge.vertexNo]){
                edge_sum += cur_edge.weight + t*cnt;
                nextVertexNo = cur_edge.vertexNo;
                cnt++;
                break;
            }
        }
    }
      
    return edge_sum;
}

int main() {
	fastio;

    int N, M, t; cin >> N >> M >> t;

    vector<vector<edgeData>> graph;
    graph.resize(N+1);

    int A, B, C;
    for(int i = 0; i < M; i++){
        cin >> A >> B >> C;

        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    int ans = prim_algorithm(graph, N, t);

    cout << ans << '\n';
}