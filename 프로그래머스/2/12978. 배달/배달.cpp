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
    vector<bool> visited(V+1);

    // init
    int start = 1;
    shortest_dist[start] = 0;
    for(pair<int, int> ed : graph[start]){
        shortest_dist[ed.first] = min(shortest_dist[ed.first], shortest_dist[start] + ed.second);
    }
    visited[start] = true;

    // O(V)
    for(int i = 0; i < V-1; i++){

        int minDist = INF;
        int selected_vtx = -1;

        // 다음 정점을 선택
        minDist = INF;
        for(int vtx = 1; vtx <= V; vtx++){
            if(!visited[vtx] && shortest_dist[vtx] < minDist){
                selected_vtx = vtx;
                minDist = shortest_dist[vtx];
            }
        }

        // 더 이상 선택할 수 있는 정점이 없는 경우 루프 탈출
        if(selected_vtx == -1) break;

        // 선택된 정점을 확정셋에 추가
        shortest_dist[selected_vtx] = minDist;
        visited[selected_vtx] = true;
        
        // 선택된 정점을 거쳐가는 경로를 추가 및 최단 경로 갱신
        for(pair<int, int> ed : graph[selected_vtx]){
            shortest_dist[ed.first] = min(shortest_dist[ed.first], shortest_dist[selected_vtx] + ed.second);
        }

    }
    
    int ans = 0;
    for(int i = 1; i <= V; i++){
        cout << shortest_dist[i] << '\n';
        if(shortest_dist[i] <= K) ans++;
    }
    return ans;
}