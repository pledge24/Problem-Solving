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
        return a.weight < b.weight;
    }
};

int prim_algorithm(vector<vector<edgeData>> graph, int N, int s, int e){

    vector<bool> visited;
    visited.resize(N+1);

    vector<int> maxCnt;
    maxCnt.resize(N+1, INT32_MAX);

    priority_queue<edgeData, vector<edgeData>, cmp> pq;

    int nextVertexNo = s;
    for(int x = 0; x < N-1; x++){
       
        visited[nextVertexNo] = true;

        for(edgeData ed : graph[nextVertexNo]){
			if(!visited[ed.vertexNo]) pq.push({ed.vertexNo, min(ed.weight, maxCnt[nextVertexNo])});     
        }

        while(!pq.empty()){
            edgeData cur_edge = pq.top(); pq.pop();
            // cout << "cur_edge.weight" << cur_edge.weight << '\n';
            if(!visited[cur_edge.vertexNo]){
                nextVertexNo = cur_edge.vertexNo;
                maxCnt[nextVertexNo] = cur_edge.weight;

                if(nextVertexNo == e) return maxCnt[e];
                break;
            }
        }
    }
      
    return 0;
}

int main() {
	fastio;

    int N, M, s, e; cin >> N >> M >> s >> e;

    vector<vector<edgeData>> graph;
    graph.resize(N+1);

    int A, B, C;
    for(int i = 0; i < M; i++){
        cin >> A >> B >> C;

        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    int ans = prim_algorithm(graph, N, s, e);

    cout << ans << '\n';
}