#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int V, E;

struct edge_data
{
    int node_no;
    int weight;
};

struct cmp
{
    bool operator()(const edge_data& a, const edge_data& b){
        return a.weight > b.weight;
    }
};

vector<vector<edge_data>> graph;
vector<bool> visited;

int prim_algorithm(){
    int edge_sum = 0;

    priority_queue<edge_data, vector<edge_data>, cmp> pq;

    int next_node_no = 1;
    for(int x = 0; x < V-1; x++){
       
        visited[next_node_no] = true;

        for(edge_data ed : graph[next_node_no]){
			if(!visited[ed.node_no]) pq.push(ed);     
        }

        while(!pq.empty()){
            edge_data cur_edge = pq.top(); pq.pop();
            if(!visited[cur_edge.node_no]){
                edge_sum += cur_edge.weight;
                next_node_no = cur_edge.node_no;
                break;
            }
        }
    }
      
    return edge_sum;
}

int main() {
	fastio;
    cin >> V >> E;
   
    graph.resize(V+1);
    visited.resize(V+1);
    
    int node1, node2, weight;
    for(int i = 0; i < E; i++){
        cin >> node1 >> node2 >> weight;
        graph[node1].push_back({node2, weight});
        graph[node2].push_back({node1, weight});
    }   
    
    int ans = prim_algorithm();

    cout << ans << '\n';

    return 0;
}