#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Edge = pair<int, int>; // dst, cost 
using Graph = vector<vector<Edge>>;

struct cmp {
    bool operator()(const Edge& edge1, const Edge& edge2){
        return edge1.second > edge2.second;
    }
};

int dijkstra(Graph& graph, int src, int dst){
    int N = graph.size() - 1;

    priority_queue<Edge, vector<Edge>, cmp> pq;
    vector<int> minDistance(N+1, 1e8);

    // init
    minDistance[src] = 0;
    pq.push(make_pair(src, 0));

    while(!pq.empty()){
        Edge path = pq.top(); pq.pop();

        if(path.second > minDistance[path.first])
            continue;

        for(Edge edge : graph[path.first]){
            int nextDst = edge.first;
            int nextDistance = path.second + edge.second;

            if(nextDistance < minDistance[nextDst]){
                minDistance[nextDst] = nextDistance;
                pq.push(make_pair(nextDst, nextDistance));
            }
        }
    }

    return minDistance[dst];
}

int main(void){
    fastio;
    int N, M, X; cin >> N >> M >> X;
    Graph graph(N+1);
    for(int i = 0; i < M; i++){
        int src, dst, cost; cin >> src >> dst >> cost;
        graph[src].push_back(make_pair(dst, cost));
    }

    int ans = 0;
    for(int i = 1; i <= N; i++){
        int dist = dijkstra(graph, i, X) + dijkstra(graph, X, i);
        ans = max(ans, dist);
    }

    cout << ans << '\n';

    return 0;
}