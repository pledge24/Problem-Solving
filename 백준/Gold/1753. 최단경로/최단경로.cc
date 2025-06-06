#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct cmp
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        return a.second > b.second;
    }
};

int V, E, K; 
vector<vector<pair<int, int>>> graph; // first : node_no, second: weight

vector<int> dijkstra(int start_node_no){

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // first : node_no, second: distance
    vector<int> shortest_dist(V+1, INT32_MAX);

    // init
    shortest_dist[start_node_no] = 0;
    pq.push({start_node_no, 0});
   
    while(!pq.empty()){
        pair<int, int> cur_path = pq.top(); pq.pop();

        if(cur_path.second != shortest_dist[cur_path.first]) continue;
        for(pair<int, int> ed : graph[cur_path.first]){

            int Next_node = ed.first;
            int nDist = cur_path.second + ed.second;
            
            if(nDist < shortest_dist[Next_node]){
                shortest_dist[ed.first] = nDist;
                pq.push({ed.first, nDist});        
            }
        }

    }

    return shortest_dist;
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
    ans = dijkstra(K);

    for(int i = 1; i<=V; i++){
        if(ans[i] == INT32_MAX){
            cout << "INF" << '\n';
        }
        else{
            cout << ans[i] << '\n';
        }
        
    }

}