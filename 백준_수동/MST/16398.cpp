#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct edgeData{
    int vertexNo;
    long long weight;
};

struct cmp
{
    bool operator()(const edgeData& a, const edgeData& b){
        return a.weight > b.weight;
    }
};

long long prim_algorithm(vector<vector<edgeData>> graph, int N){
    long long edge_sum = 0;
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
                edge_sum += cur_edge.weight;
                nextVertexNo = cur_edge.vertexNo;
                break;
            }
        }
    }
      
    return edge_sum;
}

int main() {
	fastio;
    int N; cin >> N;

    // 메모리 초과 때문에 이걸 쓰지 않았다...?
    // vector<vector<int>> graph;

    vector<vector<edgeData>> graph;
    graph.resize(N);

    long long w;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> w;
            if(i == j) continue;
            graph[i].push_back({j, w});
        }
    }

    long long ans = prim_algorithm(graph, N);

    cout << ans << '\n';

    return 0;
}