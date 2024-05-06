#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct path_data
{
    int node_no;
    int distance;
};

struct edge_data
{
    int node_no;
    int weight;
};

struct cmp
{
    bool operator()(const path_data& a, const path_data& b){
        return a.distance > b.distance;
    }
};

int V, E, K; 
vector<vector<edge_data>> graph;

vector<int> dijkstra_algorithm(int start_node_no){

    priority_queue<path_data, vector<path_data>, cmp> pq;
    vector<int> shortest_path(V+1, INT32_MAX);

    // init
    for(edge_data ed : graph[start_node_no]){
        pq.push({ed.node_no, ed.weight});
        shortest_path[ed.node_no] = ed.weight;
    }

    while(!pq.empty()){
        path_data cur_path = pq.top(); pq.pop();

        for(edge_data ed : graph[cur_path.node_no]){
            if(shortest_path[cur_path.node_no] + ed.weight < shortest_path[ed.node_no]){
                pq.push({ed.node_no, shortest_path[cur_path.node_no] + ed.weight});
                shortest_path[ed.node_no] = shortest_path[cur_path.node_no] + ed.weight;
            }
        }

    }

    return shortest_path;
}

int main() {
	fastio;
    cin >> V >> E >> K;

    graph.resize(V+1);

    int node1, node2, weight;
    graph[K].push_back({K, 0});
    for(int i = 0; i < E; i++){
        cin >> node1 >> node2 >> weight;
        graph[node1].push_back({node2, weight});
    }  
    
    vector<int> ans;
    ans = dijkstra_algorithm(K);

    for(int i = 1; i<=V; i++){
        if(ans[i] == INT32_MAX){
            cout << "INF" << '\n';
        }
        else{
            cout << ans[i] << '\n';
        }
        
    }

}