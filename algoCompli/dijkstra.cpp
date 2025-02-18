#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF INT32_MAX
using namespace std;

struct cmp
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        return a.second > b.second;
    }
};

int V, E, K; 
vector<vector<pair<int, int>>> graph; // first : vtx, second: weight
vector<int> parent;

vector<int> dijkstra3(int start){

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // first : node_no, second: distance
    vector<int> shortest_dist(V+1, INF);

    // init
    shortest_dist[start] = 0;
    pq.push({start, 0});
    fill(parent.begin(), parent.end(), -1);

    // path : (vtx, length)
    // adj : (vtx, weight)
    while(!pq.empty()){
        pair<int, int> cur_path = pq.top(); pq.pop();

        if(cur_path.second > shortest_dist[cur_path.first]) continue;
        
        for(pair<int, int> adj : graph[cur_path.first]){
            int next_vtx = adj.first;
            int next_dist = cur_path.second + adj.second;
            
            if(next_dist < shortest_dist[next_vtx]){
                shortest_dist[next_vtx] = next_dist;
                pq.push({next_vtx, shortest_dist[next_vtx]});      
                parent[next_vtx] = cur_path.first; // 다음 정점의 부모를 현재 정점으로 설정 
            }
        }

    }

    return shortest_dist;
}

// 최단 경로를 추적하는 함수
void printPath(int dst, const vector<int>& parent) {
    vector<int> path;
    
    // 목적지에서 시작 노드로 역추적
    for (int v = dst; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    
    // 경로를 역순으로 만들어 올바른 순서로 반환
    reverse(path.begin(), path.end());
    
    for(int vtx : path){
    	cout << vtx << " ";
    }
    cout << '\n';
}

// 시간복잡도 O(V^2+E)
vector<int> dijkstra2(int start){

    vector<int> shortest_dist(V+1, INF);
    vector<bool> visited(V+1);

    // init(중복 대입이 존재할 때 최소를 유지하기 위해 대입이 아닌 min비교가 들어감)
    shortest_dist[start] = 0;
    for(pair<int, int> ed : graph[start]){
        shortest_dist[ed.first] = min(shortest_dist[ed.first], shortest_dist[start] + ed.second);
    }
    visited[start] = true;

    // 시작점을 제외한 모든 정점들을 선택할 때까지 반복 O(V)
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
    
    return shortest_dist;
}

// 시간복잡도 O(VE)
vector<int> dijkstra1(int start){

    vector<int> shortest_dist(V+1, INF);

    // init
    shortest_dist[start] = 0;

    // O(V)
    for(int i = 0; i < V-1; i++){

        int minDist = INF;
        int selected_vtx = -1;

        // 확정된 정점들로부터 뻗어나가는 모든 간선 체크 O(E)
        for(int vtx = 1; vtx <= V; vtx++){
            // 아직 확정되지 않은 정점이라면 패스
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

        // 더 이상 선택할 수 있는 정점이 없는 경우
        if(selected_vtx == -1) break;

        // 선택된 정점을 확정셋에 추가
        shortest_dist[selected_vtx] = minDist;
    }
    
    return shortest_dist;
}

int main() {
	fastio;
    cin >> V >> E >> K;

    graph.resize(V+1);
    parent.resize(V+1);

    int vtx1, vtx2, weight;
    graph[K].push_back({K, 0});
    for(int i = 0; i < E; i++){
        cin >> vtx1 >> vtx2 >> weight;
        graph[vtx1].push_back({vtx2, weight});
    }  
    
    vector<int> ans;
    dijkstra1(K);
    ans = dijkstra1(K);

    for(int i = 1; i<=V; i++){
        if(ans[i] == INF){
            cout << "INF" << '\n';
        }
        else{
            cout << ans[i] << '\n';
        }
        
    }
}