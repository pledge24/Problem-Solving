#include<bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<vector<pair<int, int>>> edge_data;  // first : node_no, second : weight
vector<int> shortest_distance;
vector<int> node_dst;
priority_queue<pair<int, int>> pq;  // first : distance, second : node_no

int V, E, K;

void djk(int k){
	pq.push({0, k});

	while(!pq.empty()){
		auto [d, No] = pq.top(); pq.pop();
		
		// 해당 노드에 값이 존재하면 pass
		if(node_dst[No]){
			cout << node_dst[No] << "ssss" << '\n'; 
			continue;
		}

		// 해당 노드에 값이 없는 경우 진입.
		node_dst[No] = 1;
		shortest_distance[No] = -d;

		for(auto ed : edge_data[No]){
			pq.push({d + ed.second, ed.first});
		}
	}
}

int main(){
	fastio;
	cin >> V >> E >> K;

    edge_data.resize(V+1);
    shortest_distance.resize(V+1);
    node_dst.resize(V+1);

	for(int i = 0; i < E; i++){
		int u, v, w;
		cin >> u >> v >> w;
		edge_data[u].push_back({v, -w});
	}

	djk(K);

	for(int i = 1; i <= V; i++){
		if(node_dst[i] == 0){
			cout << "INF" << '\n';
			continue;
		}
		cout << shortest_distance[i] << '\n';
	}
	
}