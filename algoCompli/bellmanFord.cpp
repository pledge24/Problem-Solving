// vector<int> bellmanFord(vector<vector<int>>,int src, int V){

//     // Step 1 - Creating a V sized array/vector,
//     // and initializing it with a very big value.

//     vector<int> dis(V,INT_MAX); // Creating a vector dis of size V with values as INT_MAX.
//     dis[src] = 0; // Since we are already on source vertex, we can reach it within no time.

//     // Step 2 - For V-1 times, traversing over,
//     // all the edges and checking if a shorter
//     // path between any edge u to v is possible. 
//     int u,v,wt;
//     for(int i=0;i<V-1;i++) // Iterating V-1 times 
//     {
//         for(int j=0;j<edges.size();j++) // Iterating over all the edges. 
//         {
//             u = edges[j][0]; // Source vertex.
//             v = edges[j][1]; // Destination vertex.
//             wt = edges[j][2];// Weight of the edge. 

//             // If we can reach v from u in less time it 
//             // is currently required to reach v then update 
//             // the value.
//             if(dis[u]!=INT_MAX && dis[v] > dis[u] + wt)
//                 dis[v] = dis[u] + wt;
//         }
//     }

//     // Step 3 - Checking for negative edge weight cycle, 
//     // by checking if the underliying condition satifies.
//     for(int j=0;j<edges.size();j++)
//     {
//         u = edges[j][0];
//         v = edges[j][1];
//         wt = edges[j][2];
//         // If the below condition satisfies, it means negative 
//         // edge weight cycle exists. Because traversing again 
//         // is reducing the cost and in order to minimize the 
//         // cost we can traverse till infinity and hence a proper 
//         // answer can't be calculated. 
//         if(dis[u]!=INT_MAX && dis[v] > dis[u] + wt)
//             return {};
//     }
//     return dis; // returning our answer vector/array.
// }

#include <bits/stdc++.h>

#define INF 100'000'000

using namespace std;

struct Edge {
    int vtx1;
    int vtx2;
    int weight;
};

int V, E;
vector<Edge> edges;
vector<int> parent;

vector<int> bellmanFord(int start) {

    vector<int> shortest_dist(V, INF);
    
    // init
    shortest_dist[start] = 0; 
    fill(parent.begin(), parent.end(), -1);

    // V-1번 반복하여 간선 완화 + 음의 사이클 확인
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int vtx1 = edges[j].vtx1;
            int vtx2 = edges[j].vtx2;
            int weight = edges[j].weight;

            if (shortest_dist[vtx1] != INF && shortest_dist[vtx1] + weight < shortest_dist[vtx2]) {
                shortest_dist[vtx2] = shortest_dist[vtx1] + weight;
                parent[vtx2] = vtx1; // 다음 정점의 부모를 현재 정점으로 설정 

                // 음의 사이클이 확인된경우
                if(i == V-1) return {};
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

int main() {
    int V = 4; // 정점 수
    int E = 5; // 간선 수

    vector<Edge> edges = {
        {0, 1, 1},  // A -> B (1)
        {0, 2, 4},  // A -> C (4)
        {1, 2, 2},  // B -> C (2)
        {1, 3, 6},  // B -> D (6)
        {2, 3, 3}   // C -> D (3)
    };

    int source = 0; // 출발점 (A)

    return 0;
}
