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

    int m, n; 
    while(1){
        cin >> m >> n;
        if(m == 0 && n == 0){
            break;
        }

        vector<vector<edgeData>> graph;
        graph.resize(m+1);

        int x, y, z;
        int totalWeight = 0;
        for(int i = 0; i < n; i++){
            cin >> x >> y >> z;
            graph[x].push_back({y, z});
            graph[y].push_back({x, z});

            totalWeight += z;
        }

        int ans = prim_algorithm(graph, m, n);
        cout << totalWeight - ans << '\n';
    }
    
}