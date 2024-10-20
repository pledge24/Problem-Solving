#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#define INF 100'000'000

using namespace std;

int solution(int V, vector<vector<int>> road, int K) {   
    
    vector<vector<pair<int, int>>> graph(V+1);
    
    int src, dst, w;
    for(int i = 0; i < road.size(); i++){
        src = road[i][0], dst = road[i][1], w = road[i][2];
        graph[src].push_back({dst, w});
        graph[dst].push_back({src, w});
    }

    vector<int> shortest_dist(V+1, INF);
    
    // init
    shortest_dist[1] = 0;

    // O(V)
    for(int i = 0; i < V-1; i++){

        int minDist = INF;
        int selected_vtx = -1;

        // 확정된 정점들로부터 뻗어나가는 모든 간선 체크 O(E)
        for(int vtx = 1; vtx <= V; vtx++){
            // 아직 확정되지 않은 정점들은 패스
            if(shortest_dist[vtx] == INF) continue;

            for(pair<int, int> ed : graph[vtx]){
                // 도착한 정점이 확정된 정점이면 패스
                if(shortest_dist[ed.first] != INF) continue;
                
                if(shortest_dist[vtx] + ed.second < minDist){
                    minDist = shortest_dist[vtx] + ed.second;
                    selected_vtx = ed.first;
                }
            }
        }

        // 선택된 정점을 확정셋에 추가
        if(minDist != INF) shortest_dist[selected_vtx] = minDist;
    }
        
    int ans = 0;
    for(int i = 1; i <= V; i++){
        cout << shortest_dist[i] << '\n';
        if(shortest_dist[i] <= K) ans++;
    }
    return ans;
}