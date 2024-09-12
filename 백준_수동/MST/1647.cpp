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

int prim_algorithm(vector<vector<edgeData>> graph, int N, int M){
    int edge_sum = 0;
    int biggestEdgeCost = 0;
    vector<bool> visited;
    visited.resize(N+1);

    priority_queue<edgeData, vector<edgeData>, cmp> pq;

    int nextVertexNo = 1;
    for(int x = 0; x < N-1; x++){
       
        visited[nextVertexNo] = true;

        for(edgeData ed : graph[nextVertexNo]){
			if(!visited[ed.vertexNo]) pq.push(ed);     
        }

        while(!pq.empty()){
            edgeData cur_edge = pq.top(); pq.pop();
            if(!visited[cur_edge.vertexNo]){
                biggestEdgeCost = max(biggestEdgeCost, cur_edge.weight);
                edge_sum += cur_edge.weight;
                nextVertexNo = cur_edge.vertexNo;
                break;
            }
        }
    }
      
    return edge_sum - biggestEdgeCost;
}

int main() {
	fastio;
    int N; cin >> N;
    int M; cin >> M;

    // 메모리 초과 때문에 이걸 쓰지 않았다...?
    // vector<vector<int>> graph;

    vector<vector<edgeData>> graph;
    graph.resize(N+1);

    int vtx1, vtx2, w;
    for(int i = 0; i < M; i++){
        cin >> vtx1 >> vtx2 >> w;

        graph[vtx1].push_back({vtx2, w});
        graph[vtx2].push_back({vtx1, w});
    }

    int ans = prim_algorithm(graph, N, M);

    cout << ans << '\n';

    return 0;
}